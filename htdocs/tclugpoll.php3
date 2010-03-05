<?

include("poll.ini");
if (!isset($action))
    $action = "";
if (!file_exists($BasePath.$PollDataFile)) {
    include($HeaderFile);
    echo "Unable to access poll data file ($BasePath$PollDataFile). Please run the configuration script.";
    include($FooterFile);
    die();
}

$PollDataFile1 = file($PollDataFile);
$PollQuestion = $PollDataFile1[0];
$PollNumbers = explode($PollDataString, chop($PollDataFile1[1]));
$PollQuestions = explode($PollDataString, chop($PollDataFile1[2]));
$PollVotes = explode($PollDataString, chop($PollDataFile1[3]));

function GetResults($PollQuestion, $PollNumbers, $PollQuestions, $PollVotes) {
    include("poll.ini");
    echo "$PollQuestion<p>";
    $PollTotalVotes = 0;
    for ($i = 0; $i < $PollNumbers[1]; $i++) {
        $PollTotalVotes = $PollVotes[$i] + $PollTotalVotes;
    }
    if ($PollTotalVotes > 0) {
        for ($i = 0; $i < $PollNumbers[1]; $i++) {
            $tmp = ($PollVotes[$i]/$PollTotalVotes) * 100;
            $tmp = sprintf("%3.2f",$tmp);
            $tmp2 = (int) $tmp;
            $tmp3 = 100 - $tmp2;
            echo "<i>$PollQuestions[$i]</i>:<br>\n";
            if ($tmp == 0) {
                echo "<img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><img align=absmiddle src=\"$PollGraphOffFile\" height=$PollGraphHeight width=$tmp3><img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><br>";     
            }
            elseif ($tmp == 100.00) {
                echo "<img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><img align=absmiddle src=\"$PollGraphOnFile\" height=$PollGraphHeight width=$tmp2><img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><br>";     
            }
            else {
                echo "<img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><img align=absmiddle src=\"$PollGraphOnFile\" height=$PollGraphHeight width=$tmp2><img align=absmiddle src=\"$PollGraphOffFile\" height=$PollGraphHeight width=$tmp3><img align=absmiddle src=\"$PollGraphEdgeFile\" height=$PollGraphHeight width=1><br>";
            }
            echo " $tmp% ($PollVotes[$i] "; 
            if ($PollVotes[$i] == 1) {
                echo "Vote";
            }
            else {
                echo "Votes";
            }
            echo ")<br><br>\n";
        }
        echo "Total Votes: $PollTotalVotes\n";
    }
    else {
        echo "<center>No Votes Yet!</center>";
    }
}
if ($action == "vote") {
    if ($PollVoteValid == 1) {
        //Get Results
        $PollVotes[$vote] = $PollVotes[$vote] + 1;
        //Update Poll Data
                $FileToUpdate = $BasePath.$PollDataFile;
                $file = fopen($FileToUpdate,"w+");
                fwrite($file, chop($PollQuestion));
        fwrite($file, "\n");
                fwrite($file, "$PollNumbers[0]|||$PollNumbers[1]");
        fwrite($file, "\n");
        for ($i = 0; $i < $PollNumbers[1]; $i++) {
            if ($i == ($PollNumbers[1] - 1))
                fwrite($file, "$PollQuestions[$i]");
            else
                fwrite($file, "$PollQuestions[$i]|||");
        }
        fwrite($file, "\n");
        for ($i = 0; $i < $PollNumbers[1]; $i++) {
            if ($i == ($PollNumbers[1] - 1))
                fwrite($file, "$PollVotes[$i]");
            else
                    fwrite($file, "$PollVotes[$i]|||");
        }
                fclose($file);
        include($HeaderFile);
        GetResults($PollQuestion, $PollNumbers, $PollQuestions, $PollVotes);
        include($FooterFile);
    } else {
            if ($PollWarnCheaters == 1) {
            include($HeaderFile);
                echo "You have already voted!";
            include($FooterFile);
            }
        else {
            include($HeaderFile);
            GetResults($PollQuestion, $PollNumbers, $PollQuestions, $PollVotes);
            include($FooterFile);
        }
    }
} elseif ($action == "viewresults") {
    include($HeaderFile);
    GetResults($PollQuestion, $PollNumbers, $PollQuestions, $PollVotes);
    include($FooterFile);
} elseif ($showresults == 1) {
    include($HeaderFile);
    GetResults($PollQuestion, $PollNumbers, $PollQuestions, $PollVotes);
    include($FooterFile);
} else {
include($HeaderFile);
    echo "$PollQuestion\n"; ?>
    <p>
    <form action="index.php3" method="post">
    <input type="hidden" name="action" value="vote">
    <? 
    for($i = 0; $i < $PollNumbers[1]; $i++) {
        if ($i == 0)
            echo "<input type=radio name=vote value=$i checked> $PollQuestions[$i]<br>\n";
        else
            echo "<input type=radio name=vote value=$i> $PollQuestions[$i]<br>\n";
    }
    ?>
    <br>
    </font>
    <table align=center border=0>
    <tr>
    	<td><input type="submit" value="Vote"></td></form>
    	<td><A HREF="/index.php3?action=viewresults">View Results</A></td>
    </tr>
    </table>
<?
include($FooterFile);
}
?>

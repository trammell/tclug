<?php

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

if ($action == "vote") {
    $PollVoteValid = 1;
    if ($UseCookies == 1) {
        $PollCookieName = $PollCookiePrefix.$PollNumbers[0];
        if(isset($$PollCookieName) == 1) {
                $PollVoteValid = 0;
        }
            else {
            setCookie($PollCookieName, "1", time()+$PollCookieExpire);
        }
    }
} else {
        $PollCookieName = $PollCookiePrefix.$PollNumbers[0];
        if(isset($$PollCookieName) == 1) {
		$showresults = 1;
	print "test";
	}
}
?>

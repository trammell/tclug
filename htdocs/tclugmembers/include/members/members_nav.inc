<?
$query = mysql_query( "SELECT Count(*) as total FROM $memberstable") or die (mysql_error());
$row = mysql_fetch_array($query);
        $total = $row["total"];


print "\n\n<BR>\n";
print "<CENTER>\n";

$vor = $show + $limit;
$back = $show - $limit;


if ($show - $limit >= 0){
print "::<a href=\"$path_to_members_index/$members_script/list/$back/\">Previous Page</a>::&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n";
}

elseif (($show + $limit) >= $total) {
}

if (($show + $limit) < $total){

print "::<a href=\"$path_to_members_index/$members_script/list/$vor/\">Next Page</a>::\n";

}
print "\n</CENTER>\n";
?>

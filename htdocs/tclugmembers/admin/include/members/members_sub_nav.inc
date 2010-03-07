<?
  $query = mysql_query( "SELECT Count(*) as total FROM $mem_subtable") or die(mysql_error()); 
  $row=mysql_fetch_Array($query);
  $total=$row[total];

print "<CENTER>";

$vor = $show + $limit;
$back = $show - $limit;


if ($show - $limit >= 0){
print "::<a href=\"$PHP_SELF?mode=members_sub_list&show=$back\">Previous Page</a>::&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}

elseif (($show + $limit) >= $total) {
}

if (($show + $limit) < $total){
print "::<a href=\"$PHP_SELF?mode=members_sub_list&show=$vor\">Next Page</a>::";
}
print "</CENTER>";
?>

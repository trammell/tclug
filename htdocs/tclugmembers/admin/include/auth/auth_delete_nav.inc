<BR><BR><BR><BR><BR>
<?

$vor = $show + $limit;
$back = $show - $limit;


if (($show + $limit) < $total){

print "<a href=\"$PHP_SELF?mode=delete_list&show=$vor\">Next Page</a>&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";

}

elseif (($show + $limit) >= $total) {
}


if ($show - $limit >= 0){
print " <a href=\"$PHP_SELF?mode=delete_list&show=$back\">Previous Page</a>";
}

?>

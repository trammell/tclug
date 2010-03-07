<?
$result = MYSQL_QUERY($insert);
$query = "DELETE FROM $mem_subtable WHERE(artnr=$msid)";
$insert = MYSQL_QUERY($query);
print "Submission $msid should now be deleted....";
print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"1; URL=$path_to_admin/$membersadmin_script?mode=members_sub_list\">";
?>

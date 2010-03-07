<?
$result = MYSQL_QUERY($insert);
$query = "DELETE FROM $memberstable WHERE(artnr=$mid)";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
print "Member $mid should now be deleted....";
print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"1; URL=$path_to_admin/$membersadmin_script?mode=members_edit_list\">";
?>

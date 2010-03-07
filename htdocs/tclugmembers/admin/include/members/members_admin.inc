<?
$TITLE = "$sitename Admin : Members Admin";
include("$head");
include("$adminpath/include/login_check.inc");
print "<p>";

if ($status != 'Author'){
print ("
<b>What would you like to do?:</b><br>
<A HREF=\"$path_to_admin/\">Go back to <i>Main</i> admin</a>
<ul>
	<li><a href=\"$path_to_admin/$membersadmin_script?mode=members_add\">Add a new Member</a><br>
	<li><a href=\"$path_to_admin/$membersadmin_script?mode=members_edit_list\">Modify/Delete a Member</a><br>
	<li><a href=\"$path_to_admin/$membersadmin_script?mode=members_sub_list\">Member Submissions</a><br>
</ul>
	");
} else {
print "<b>You are unauthorized to view this resource</b>";
 	}
include("$foot");
?>

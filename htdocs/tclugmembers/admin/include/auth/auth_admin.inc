<?
$TITLE="$sitename Admin : Authors : Select Tool";
include("$head");
include("$adminpath/include/login_check.inc");
if ($status != "Admin"){
print "<p><b>You are not authorized to View this Resource</b>";
} else {
print ("
	<p>
<b>What would you like to do?:</b><br>
<A HREF=\"$path_to_admin/\">Go back to <i>Main</i> admin</a>
   <ul>
	<li><a href=\"$path_to_admin/$authadmin_script?mode=add\">Add an Author</a><br>
	<li><a href=\"$path_to_admin/$authadmin_script?mode=edit_list\">Edit an Author</a><br>
	<li><a href=\"$path_to_admin/$authadmin_script?mode=delete_list\">Delete an Author</a><br>
   </ul>
   ");
}
include("$foot");
?>

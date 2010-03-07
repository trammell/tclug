<?
include("$head");
include("$adminpath/include/login_check.inc");
print ("
<p>
<b>Edit a Member</b>
<br>
<a href=\"$path_to_admin/$membersadmin_script\">Back to admin</a>
<p>
<table width=85% border=0>
	");

if (!isset($show)) $show=0;
$query = mysql_query( "SELECT artnr,name FROM $memberstable order by artnr desc LIMIT $show,  $limit") or die(mysql_error());
while ($row = mysql_fetch_array($query)){
	$mid = $row["artnr"];
	$name = $row["name"];

print ("
  <tr>
	<td>
<p>$name
	</td>
	<td>
<a href=\"$path_to_admin/$membersadmin_script?mode=members_edit&mid=$mid\">Edit</a>
	</td>
	<td>
<a href=\"$path_to_admin/$membersadmin_script?mode=members_deleted&mid=$mid\">Delete</a>
	</td>
  </tr>
");
$i++;
   } // End While
print "</table>";
include("$adminpath/include/members/members_edit_nav.inc");
include("$foot");
?>

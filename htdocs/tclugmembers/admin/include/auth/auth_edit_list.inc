<?
$TITLE = "$sitename Admin : Authors : Edit List";
include("$head");
include("$adminpath/include/login_check.inc");
?>
<p>
<b>Edit an Author</b><br>
<a href="<?php echo "$path_to_admin/$authadmin_script"; ?>">Go back to admin</a>
<br>
<blockquote>
   <ul>
<?
$query = mysql_query("SELECT artnr,name,user from $authorstable order by artnr") or die (mysql_error());
WHILE ($row = mysql_fetch_array($query)){
	$sid = $row["artnr"];
	$name = $row["name"];
	$user = $row["user"];
print ("	<li><a href=\"$path_to_admin/$authadmin_script?mode=edit&item=$sid\"> $user </b></a> - $name");
  } //End While
?>
   </ul>
</blockquote>
<?
include("$adminpath/include/auth/auth_edit_nav.inc");
include("$foot");
?>

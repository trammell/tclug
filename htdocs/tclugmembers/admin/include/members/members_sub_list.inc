<?
$TITLE = "$sitename Admin : Members Submissions List";
include("$head");
include("$adminpath/include/login_check.inc");

if ($status == "Author"){
print "<p><b>Unathorized to view this resource</b>";
} else {
print ("
<p>
<b>Submit Member</b><br>
<a href=\"$path_to_admin/$membersadmin_script\">$back_to_admin</a>
<p>
<TABLE WIDTH=85% BORDER=\"0\" CELLPADDING=\"2\" CELLSPACING=\"1\"><TR>
<TD><b>Name:</b></TD>
<TD>&nbsp;</TD>
<TD>&nbsp;</TD>
</TR>
	");

if (!isset($show)) $show=0;
$query = mysql_query( "SELECT artnr,name,email,user FROM $mem_subtable order by artnr desc LIMIT $show, $limit") or die(mysql_error());
while ($row = mysql_fetch_array($query)){
	$msid = $row["artnr"];
	$name = $row["name"];
	$email = $row["email"];
	$user = $row["user"];
	$query2 = mysql_query( "SELECT user FROM members WHERE user=\"$user\" AND email=\"$email\"") or die(mysql_error());
	if (mysql_fetch_array($query2)) {
		$submitted="Yes";
	} else {
		$submitted="No";
	}
print ("
<TR>
   <TD>
<p>$name
   </TD>
   <TD width=20%>
<a href=\"$path_to_admin/$membersadmin_script?mode=members_sub_edit&msid=$msid\">Submit</a> $submitted
   </TD>
   <TD>
<A HREF=\"$path_to_admin/$membersadmin_script?mode=members_sub_deleted&msid=$msid\">Delete?</A>
   </TD>
</TR>");
$i++;
  } // End While
print "</TABLE>";
} //endif
include("$adminpath/include/members/members_sub_nav.inc");
include("$foot");
?>

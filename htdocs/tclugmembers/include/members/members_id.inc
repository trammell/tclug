<?
include("$head");

$news_query = mysql_query("select *,unix_timestamp(date) as timestamp from $memberstable where artnr=\"$mid\"") or die(mysql_error());
$row  =  mysql_fetch_array($news_query);
        $record_number=$row["artnr"];
        $name=$row["name"];
        $bio=stripslashes($row["bio"]);
	$status=$row["status"];
        $email=$row["email"];
	$showemail=$row["showemail"];
        $url=$row["url"];
        $timestamp=$row["timestamp"];
        $active=$row["active"];

$date = date("$date_format",$timestamp);

print ("
<TABLE WIDTH=\"85%\" CELLPADDING=\"3\" CELLSPACING=\"0\" BORDER=\"0\">
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Name:
	</TD>
	<TD WIDTH=\"80%\">
<P>
&nbsp; $name
	</TD>
   </TR>
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
URL:
	</TD>
	<TD WIDTH=\"80%\">
<P>
	");
if($url == '')
        { print ("&nbsp; N/A\n"); }
        else
        { print ("&nbsp; <a href=\"$url\">$url</a>\n"); }

print ("
	</TD>
   </TR>
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Status:
	</TD>
	<TD WIDTH=\"80%\">
<P>
&nbsp; $status
	</TD>
   </TR>
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Last Updated:
	</TD>
	<TD WIDTH=\"80%\">
<P>
&nbsp; $date
	</TD>
   </TR>
");
if ($showemail!="No") {
if ($showemail=="Converted") {
	$email=preg_replace("/@/", " at ", $email);
	$email=preg_replace("/\./", " dot ", $email);
}

print ("
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Email:
	</TD>
	<TD WIDTH=\"80%\">
<P>
	");

if($email != '')
        { print ("&nbsp; <a href=\"mailto:$email\">$email</a>\n"); }
        else
        { print ("&nbsp; N/A\n"); }

print ("
	</TD>
   </TR>
	");
}

if($bio != '') {
   print ("
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Bio:
	</TD>
	<TD WIDTH=\"80%\">
<P>
$bio
	</TD>
   </TR>

"); }

print ("
   <TR>
	<TD ALIGN=\"Right\" VALIGN=\"TOP\" WIDTH=\"20%\">
<P>
Active:
	</TD>
	<TD WIDTH=\"80%\">
<P>
	");

if($active != 'Yes')
	{ print ("&nbsp; $active\n"); }
	else
	{ print ("&nbsp; <FONT COLOR=\"RED\">$active</FONT>\n"); }

print ("
	</TD>
   </TR>
</TABLE>
<BR>
<TABLE align=\"center\" WIDTH=\"50%\" CELLPADDING=\"0\" CELLSPACING=\"0\" BORDER=\"0\">
   <TR>
	<TD ALIGN=LEFT>
<a href=\"$path_to_members_index/$members_script/list/\">Return to Members Index</a>
	</TD>
	<TD ALIGN=RIGHT>
<a href=\"https://www.mn-linux.org/$path_to_members_index/$members_script/edit/\">Edit your Info</a>
	</TD>
   </TR>
</TABLE>
	");

include("$foot");

?>

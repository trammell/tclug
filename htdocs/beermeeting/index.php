<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
        <title>TCLUG - Twin Cities Linux Users Group</title>
<meta http-equiv="author" content="TCLUG Webmaster">
<meta http-equiv="Reply-to" content="webmaster@mn-linux.org">
<meta http-equiv="Keywords" content="Twin Cities Linux Users Group, Linux, Minnesota,
Advocacy, Linux Resources, Linux Links, Mailing List, Local Events">
<meta http-equiv="Description" content="The Twin Cities Linux User's Group is a
local Linux advocacy group dedicated to expanding the use of Linux, both
professionally and personally.  The group is comprised entirely of
volunteers.">
<style>
body, center, form, hr, p, td, th { font-family: Helvetica,Verdana,Sans-Serif;
                     color: #000000;}

.header {       font-family: Helvetica,Verdana,sans-serif;
                        font-weight: bold;
                        color: #000080;}

.copy  {        font-family: Helvetica,Verdana,sans-serif;
                        color: #999999;}
</style>
</head>

<body bgcolor="white" background="/img/mn-linux_bg.gif" marginwidth="0" marginheight="0" topmargin="0"
leftmargin="0">

<?php
$db = mysql_connect ("mysql2.real-time.com", "cfandre", "web");
mysql_select_db("wwwmnlinuxorg",$db);
$sql = "select * from beermeeting";
$result = mysql_query($sql, $db);
$numrows = mysql_numrows($result);
$row = mysql_fetch_row ($result);
$date = $row[0];
$location = $row[1];
?>

<table border="0" cellpadding="0" cellspacing="0" width="751">
<tr>
        <td><img src="/images/tclugminn.jpg" width=500 height=150 border=0 alt=""></td>
</tr>
</table>
<table border="0" cellpadding="5" cellspacing="0" width="751">
<tr>
        <td width="600">
<table width=600 border="0" align="center" cellspacing="0" cellpadding="1">
<tr>
  <td bgcolor="#000000" align="center">
<table width=100% cellspacing=0 cellpadding=20 border=0 bgcolor="ivory">
<tr>
      <td align="left"><div class="header" align="center">
<font size=+2>Beer Meeting</font></div>

<P>
A TCLUG beer meeting is a monthly get-together where TCLUG members can get to know one another and share a beer. The beer meetings are open to anyone and everyone, so don't be afraid to show up.
<P>
<B>When:
<BR></B>
<?php print $date ?>
<P>
<B>Where:</B>
<BR>
<?php print $location ?>
<P>
Hope to see you there!
<P>


</td>
</tr>
</table></td>
</tr>
</table>
<?php include("../footer.inc") ?>
</td>
        <td width="151" align="right" valign="top">
<table border="0" cellpadding="0" cellspacing="0" width="140">
<tr>
        <td align="right"><br>
<?php include("../links.inc") ?>
</td>
</tr>
</table>
</td>
</tr>
</table>
<br>
</body>
</html>

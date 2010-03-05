<?
$title="TCLUG - Twin Cities Linux Users Group";
include("/usr/httpd/virtual/www.mn-linux.org/html/header.inc");
?>
<table border="0" cellpadding="0" cellspacing="0" width="751">
<tr>
        <td><img src="/images/tclugminn.jpg" width=500 height=150 border=0 alt="Twin Cities Linux Users Group - Minneapolis, Minnesota"></td>
</tr>
</table>
<table border="0" cellpadding="5" cellspacing="0" width="95%">
<tr>
        <td width="95%">
<table width=95% border="0" align="center" cellspacing="0" cellpadding="1">
<tr>
  <td bgcolor="#000000" align="center">
<table width=100% cellspacing=0 cellpadding=20 border=0 bgcolor="ivory">
<tr>
      <td align="left"><div class="header" align="center">
<font size=+2>Latest News</font></div>
<P>
<?

include ("../../include/wwwmnlinuxorg.inc");
tclug_db_connect () or exit;

$sql = "SELECT *,UNIX_TIMESTAMP(date) from news order by date desc";
$result = mysql_query($sql);
$numrows = mysql_numrows($result);

print "<UL>";
while ($row=mysql_fetch_array($result)) {
                $stringdate = date("l, F d, Y",$row[3]);
                print "<LI><B>$stringdate</B>\n";
                print "<blockquote>";
		print "$row[news]\n";
		print "</blockquote>";
}
print "</UL>";
?>

</td>
</tr>
</table></td>
</tr>
</table>

<? include("../footer.inc") ?>


</td>
        <td width="151" align="right" valign="top">
<table border="0" cellpadding="0" cellspacing="0" width="140">
<tr>
        <td align="right"><br>
<? include("../links.inc") ?>
</td>
</tr>
</table>        
</td>
</tr>
</table>
<br>
</body>
</html>

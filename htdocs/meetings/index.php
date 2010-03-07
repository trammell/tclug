<?
$title="TCLUG - Twin Cities Linux Users Group Meetings";
include("/usr/httpd/virtual/www.mn-linux.org/html/header.inc");
?>



<table border="0" cellpadding="0" cellspacing="0" width="751">
<tr>
        <td><img src="/images/tclugminn.jpg" width=500 height=150 border=0 alt="Twin Cities Linux Users Group - Minneapolis, Minnesota"></td>
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
<font size=+2>Meeting Information</font></div>

<P>
<BR>
Our meetings are scheduled for the first Saturday of each month from noon until 2pm. We will probably be meeting at the UofM, but this is decided on a month-to-month basis.
<P>
We also have bi-weekly beer meetings at various locations in the Twin Cities area. Check the <A HREF="/beermeeting/">Beer Meeting page</A> for more info.
<P>
<div class="header" align="center">
<font size=+1>Next TCLUG Meeting</font></div>
<P>

<P>
<B>When:
<BR></B>
<?print $date ?>
<P>
<B>Topic:
<BR></B>
<?print $topic ?>
<P>
<B>Where:</B>
<BR>
<? print $location ?>
<P>
Hope to see you there!
<P>
<? include("pastmeetings.inc") ?>

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

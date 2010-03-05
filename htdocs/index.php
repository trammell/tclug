<? 
$title="TCLUG - Twin Cities Linux Users Group";
include("/usr/httpd/virtual/www.mn-linux.org/html/header.inc");
?>
<table border="0" cellpadding="0" cellspacing="0" width="90%">
<tr>
        <td><A HREF="http://www.mn-linux.org"><img src="/images/tclugminn.jpg" width=500 height=150 border=0 alt="Twin Cities Linux Users Group - Minneapolis, Minnesota"></A></td>
<td>
</td>
</tr>
</table>
<table border="0" cellpadding="5" cellspacing="0" width="95%">
<tr valign=top>
        <td width="100%">
<table width=100% border="0" align="center" cellspacing="0" cellpadding="1">
<tr>
  <td bgcolor="#000000" align="center">
<table width=100% cellspacing=0 cellpadding=20 border=0 bgcolor="ivory">
<tr>
      <td align="left"><div class="header" align="center">
<font size=+2>Welcome to TCLUG!</font></div>
<HR>
<B><A HREF="/news">Latest News:</A></B><BR>
<?
include ("../include/wwwmnlinuxorg.inc");
tclug_db_connect () or exit;
include("latestnews.inc");
?>

<HR>
<table><tr><td width=75%>
<B>Random TCLUG Member Site Link:</B><BR>
<? include("randomtclugsite.inc") ?>
</td><td>
<a href="http://www.cafeshops.com/tclug"><img src="/images/tclugstore.gif" border=0></a>
</td></tr></table>
<HR>
<P>The <B>Twin Cities Linux Users Group</b> is a group of
 <A HREF="http://www.linux.org">Linux</A> users in the Minneapolis, MN area.
If you are curious about Linux, or looking for technical answers, we
encourage you to join us.  If you're not in the local Twin Cities area, there 
may be a LUG in your area.  Check our list of <a href="/othergroups/">other groups 
</a> to see if there's one in your area.</p>

The <B>TCLUG</B> holds monthly meetings in which we discuss various topics related to Linux. This gives our members a chance to interact with one another while learning about Linux.
About every 4-5 months we have an <A HREF="/installfest/">installfest</A>, which allows new users to get "a helping hand" while installing Linux.
Our <A HREF="/mailinglists/">mailing list</A> is full of discussions about Linux, hardware, software, and everything in between, and is open to the public.
There is no fee to join the group, and meetings are open to everyone.
If you have any questions about our group, please e-mail <A HREF="mailto:info@mn-linux.org">info@mn-linux.org</A>. Any questions or comments about this site should go to <A HREF="mailto:webmaster@mn-linux.org">webmaster@mn-linux.org</A>.
<TABLE><TR><TD>
<HR>
<P>
<i><b>So how do I join?</b></i> Since the group is 100% free, just enter yourself on the <A HREF="/tclugmembers/members.php">members page</A>, attend some <A HREF="/meetings/">meetings</A> and join one of the <A HREF="/mailinglists/">mailing lists</A>. No matter what your skill level or technical proficiency, everyone is
welcome, and we hope to show you how enjoyable Linux can be.  :-)</p>

</TD><TD>
</TD></TR></TABLE>
</td>
</tr>
</table></td>
</tr>
</table>
<? include("footer.inc") ?>
</td>
        <td width="151" align="right" valign="top">
<table border="0" cellpadding="0" cellspacing="0" width="140">
<tr>
        <td align="right"><br>
<? include("links.inc") ?>
</td>
</tr>
</table>        
</td>
</tr>
</table>
<br>
</body>
</html>

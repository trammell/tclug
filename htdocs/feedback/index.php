<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
        <title>TCLUG - Twin Cities Linux Users Group</title>
<meta http-equiv="author" content="TCLUG Webmaster">
<meta http-equiv="Reply-to" content="webmaster@mn-linux.org">
<meta http-equiv="Keywords" content="Twin Cities Linux Users Group, Linux, Minnesota, Advocacy, Linux Resources, Linux Links, Mailing List, Local Events">
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

<body bgcolor="white" background="" marginwidth="0" marginheight="0" topmargin="0"
leftmargin="0">
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

<CENTER><H2>TCLUG Visitor Feedback</h2></center>

<?php
if ($Submit) {
	while (list($name, $value) = each($HTTP_POST_VARS)) {
		$message = $message . "$name = $value\n";
	}
	$message = $message . "REFERER: $HTTP_REFERER\nUSER_AGENT: $HTTP_USER_AGENT\nREMOTE_ADDR: $REMOTE_ADDR\n";
	mail("webmaster@mn-linux.org","TCLUG Web feedback","$message");
	print "<P>Thank you for your comments!  If you asked a question, we will contact you as quickly as possible.</p>";
} else {
?>

<P>We thank you very much for visiting us!  Please provide as much detail
in the comments as you can, and we'll get in contact with you as soon as
possible.</p>

<CENTER>
<TABLE border=0>
<TR><TD>
<FORM method="POST" action="<?php print $PHP_SELF ?>">
<input type="hidden" name="form_owner" value="webmaster@mn-linux.org">
<input type="hidden" name="field_order"
value="regarding,first_name,last_name,company,from,phone,comments">
<input type="hidden" name="subject" value="TCLUG Visitor Feedback">
<input type="hidden" name="log_file" value="1">
<input type="hidden" name="validate:first_name,last_name,comments"
value="has text">
<input type="hidden" name="validate:from" value="e-mail">
<input type="hidden" name="validateif:phone" value="telephone">
<CENTER>
<TABLE border="0" cellpadding="3" cellspacing="0" align="left"
bgcolor="ivory">
<TR><TD><br>*First Name</td><TD><br><input type="text"
name="first_name"></td></tr>
<TR><TD>*Last Name</td><TD><input type="text" name="last_name"></td></tr>
<TR><TD>Company</td><TD><input type="text" name="company"></td></tr>
<TR><TD>*Email Address</td><TD><input type="text" name="from"></td></tr>
<TR><TD>Telephone</td><TD><input type="text" name="phone"></td></tr>
<TR><TD colspan=2 align="center">(* denotes required fields)</td></tr>
<TR><TD>Regarding</td><TD><select name="regarding">
<option selected value="General Questions">General Questions
<option value="TCLUG Meeting">TCLUG Meeting
<option value="TCLUG Site">TCLUG Site
<option value="Next Installfest">Next Installfest
</select></td></tr>
<tr><td colspan="2">
Comments:<BR>
<textarea name="comments" cols="40" rows="10" wrap="soft"></textarea>
<BR><BR>
<CENTER><input type="submit" name="Submit" value="Submit"></center></td></tr>
</table>
</center>
</form>
</td></tr></table>
</center>

<?php } ?>
</td>
</tr>
</table></td>
</tr>
</table>

<CENTER>
<P class="copy"><font size=-1>
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


<?
while(list($key,$val)=each($_POST))
{
$$key = $val;
$post=1;
}

if (($post) && !($name)) {
include ("/usr/httpd/virtual/www.mn-linux.org/include/wwwmnlinuxorg.inc");
tclug_db_connect () or exit;

print "<HTML><HEAD><TITLE>Someone forget their password...</TITLE></HEAD><BODY>";
print "<H1>Someone forgot their password...</H1>";
$query = "select artnr,email,name,password from members where email=\"$email\"";
print "$query<BR>";

$result = mysql_query($query) or die("Query failed");

$numrows= mysql_num_rows($result);
if ($numrows == 0) {
	print "Sorry, there were no matching members with that email address.<br>Please email the administrator at <A HREF=\"mailto:webmaster@mn-linux.org\">webmaster@mn-linux.org</A> with any problems.\n";
} else {
while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
	$artnr = $line["artnr"];
	$password = $line["password"];
	$email = $line["email"];
	$name= $line["name"];
}

$myname = "Webmaster";
$myemail = "webmaster@mn-linux.org";

$contactname = "$name";
$contactemail = "clay@fandre.com";

$message = "Your password is $password";
$subject = "Password for TCLUG Member page";


$headers .= "MIME-Version: 1.0\r\n";
$headers .= "Content-type: text/html; charset=iso-8859-1\r\n";
$headers .= "From: ".$myname." <".$myemail.">\r\n";
$headers .= "To: ".$contactname." <".$contactemail.">\r\n";
$headers .= "Reply-To: ".$myname." <$myreplyemail>\r\n";
$headers .= "X-Priority: 1\r\n";
$headers .= "X-MSMail-Priority: High\r\n";
$headers .= "X-Mailer: Just My Server";

print "mail: $contactemail, $subject, $headers<br>\n";
mail($contactmail, $subject, $headers);
print "You password has been emailed to you account at $email<br>\n";
mysql_free_result($result);
}
} else {
print "<H1>Forget your password?</H1>";
print "<FORM METHOD=post ACTION=\"/tclugmembers/forget/\">";
print "Enter your email address you registered with<BR><INPUT TYPE=text NAME=email SIZE=30 MAXSIZE=32>";
}
?>


<?
while(list($key,$val)=each($_POST))
{
$$key = $val;
$post=1;
}

if (($post) && !($name)) {
include ("/usr/httpd/virtual/www.mn-linux.org/include/wwwmnlinuxorg.inc");
tclug_db_connect () or exit;

print "<HTML><HEAD><TITLE>TCLUG Member search results</TITLE></HEAD><BODY>";
print "<H1>TCLUG Member search results</H1>";
$query = "select artnr,name,url from members where lower(name) like lower(\"%$search%\") or lower(bio) like lower(\"%$search%\") order by name";
#print "$query";

#$query = "select name,bio,url from members where artnr = 4";
$result = mysql_query($query) or die("Query failed");

$numrows= mysql_num_rows($result);
if ($numrows == 0) {
	print "Sorry, there were no matching members.<br>\n";
} else {
print "<table border=1>\n";
while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
	print "\t<tr>\n";
	$artnr = $line["artnr"];
	foreach ($line as $col_value) {
		print "\t\t<td><A HREF=\"/tclugmembers//members.php/zoom/$artnr/\">$col_value</A></td>\n";
	}
	print "\t</tr>\n";
}
print "</table>\n";
mysql_free_result($result);
}
}
print "<FORM METHOD=post ACTION=\"/tclugmembers/search/index2.php\">";
print "<B>Search for member</B> (% for everyone)<BR><INPUT TYPE=text NAME=search SIZE=30 MAXSIZE=32>";

?>

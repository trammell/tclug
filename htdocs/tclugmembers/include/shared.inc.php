<?
$theme = "classic";

$limit = 30 ; /* Either a number or "all". */
$begin = 8 ; /* for the older articles nav.  Must be on number higher than $limit.. */

$defaultcount = "20";

/*
Script name definitions
*/
$members_script = "members.php";

/*
Admin Scripts
*/
$membersadmin_script = "membersadmin.php";
$authadmin_script = "authadmin.php";
$prefsadmin_script = "prefsadmin.php";

$path = "/usr/httpd/virtual/www.mn-linux.org/html/tclugmembers" ; /* Path to your Members Directory */
$adminpath = "$path/admin" ; /* Path to your News Admin directory */

$button = "<input type=\"submit\" value=\"Submit\">";

$path_to_members_index = "/tclugmembers/";
/* Please fill in the full webroot path to the news/index.php file without a trailing "/". */
$path_to_admin = "/tclugmembers/admin";
/* Please fill in the full webroot path to the authors/index.php file without a trailing "/". */

/* 
Set the full disk path to the head.html and foot.html or the path relative to the index.php file. 
*/
$head = "$path/include/$theme/header.tmpl";
$foot = "$path/include/$theme/footer.tmpl";
$sitename = "TCLUG Members Page";
$siteurl = "http://www.mn-linux.org";
$adminemail = "clay@fandre.com";
$description = "Twin Cities Linux Users Group";

/* 
Edit to make the script connect to your MySQL server with the right username and password.
*/

$hostname = "mysql2";     // Usually localhost.
$db_user = "cfandre"; 	     // If you have no username, leave this space empty.
$db_pass = "web"; 	     // The same applies here.
$dbName = "wwwmnlinuxorg"; 	     // This is the main database you connect to.

$memberstable = "members";
$mem_subtable = "submembers";
$authorstable = "authors";   // This is the authors table

/*
Members script stuff
*/
$mem_subemail = "$adminemail";
$mem_subject = "New $sitename Member submission";
$mem_mailstuff = "There is a new member submission on $sitename";


/*
Date info
*/
$datetime = date("Y-m-d H:i:s");
$nicedate = date("M. d, Y g:i a");
$date_format = "M. d, Y <\i>g:i a</\i>";
?>

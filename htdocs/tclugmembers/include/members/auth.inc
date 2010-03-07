<?
$path = "$DOCUMENT_ROOT/tclugmembers";
require("$path/include/shared.inc.php");
    cfunction authenticate() {
	global $sitename;
        Header("WWW-authenticate: basic realm=\"$sitename\"");
        Header("HTTP/1.0 401 Unauthorized");
        $title="Invalid Login";
        print "In order to proceed you will need a valid username/password.";
        exit;
    }

    if(!isset($PHP_AUTH_USER)) {
        authenticate();
    } else {
        mysql_pconnect("$hostname","$db_user","$db_pass") or die("Unable to connect to SQL server");
        mysql_select_db("$dbName") or die("Unable to select database");
        $user=strtolower($PHP_AUTH_USER);
//$pass = md5($PHP_AUTH_PW);
$pass = $PHP_AUTH_PW;
        $query = mysql_query("select * from $memberstable where user='$user' and password='$pass'");
        if(!mysql_num_rows($query)) {
            authenticate();
        }
    }
?>

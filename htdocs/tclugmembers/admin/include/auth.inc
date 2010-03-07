<?
$path = "$DOCUMENT_ROOT/tclugmembers";
require("$path/include/shared.inc.php");
    cfunction authenticate() {
        Header("WWW-authenticate: basic realm=\"Administration\"");
        Header("HTTP/1.0 401 Unauthorized");
        $title="Invalid Login";
        print ("In order to proceed you will need a valid username/password.");
        exit;
    }

    if(!isset($PHP_AUTH_USER)) {
        authenticate();
    } else {
        mysql_pconnect("$hostname","$db_user","$db_pass") or die("Unable to connect to SQL server");
        mysql_select_db("$dbName") or die("Unable to select database");
        $user=strtolower($PHP_AUTH_USER);
	$pass = crypt($PHP_AUTH_PW, "lI");
		$query = mysql_query("select * from $authorstable where user='$user' and password='$pass'");
        if(!mysql_num_rows($query)) {
            authenticate();
		}
    }
?>

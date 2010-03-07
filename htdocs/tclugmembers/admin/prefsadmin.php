<?
$path = "$DOCUMENT_ROOT";
include("include/auth.inc");
require("$path/include/shared.inc.php");
include("$path/include/lib.inc.php");

if (!isset($mode)){ $mode = "prefs"; } //End If

/*
  Begin Preferences includes
*/

if ($mode == "prefs"):
require( "$adminpath/include/prefs/prefs.inc");

elseif ($mode == "change_prefs"):
require( "$adminpath/include/prefs/prefs_change.inc");

endif;

MYSQL_CLOSE();
?>

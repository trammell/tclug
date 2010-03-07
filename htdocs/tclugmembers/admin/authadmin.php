<?
$path = "$DOCUMENT_ROOT";
include("include/auth.inc");
require("$path/include/shared.inc.php");
include("$path/include/lib.inc.php");
if (!isset($mode)){
$mode = "admin"; 
   }

if ($mode == "delete_list") :
require( "$adminpath/include/auth/auth_delete_list.inc");

elseif ($mode ==  "delete"):
require( "$adminpath/include/auth/auth_deleted.inc");

elseif ($mode ==  "add"):
require( "$adminpath/include/auth/auth_add.inc");

elseif ($mode ==  "added_article"):
require ( "$adminpath/include/auth/auth_added.inc");
 
elseif ($mode == "edit_list") :
require( "$adminpath/include/auth/auth_edit_list.inc");
 
elseif ($mode ==  "edit"):
require( "$adminpath/include/auth/auth_edit.inc");
 
elseif ($mode ==  "change"):
require( "$adminpath/include/auth/auth_edited.inc");

elseif ($mode ==  "admin"):
require( "$adminpath/include/auth/auth_admin.inc");

endif;

MYSQL_CLOSE();
?>

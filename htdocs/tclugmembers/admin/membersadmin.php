<?
require( "include/auth.inc");
require( "../include/shared.inc.php");
include( "$path/include/lib.inc.php");
if (!isset($mode)) $mode='members_admin';


if ($mode ==  "members_admin") :
require( "$adminpath/include/members/members_admin.inc");

elseif ($mode ==  "members_add"):
require( "$adminpath/include/members/members_add.inc");

elseif ($mode ==  "members_added"):
require ( "$adminpath/include/members/members_added.inc");
 
elseif ($mode == "members_edit_list") :
require( "$adminpath/include/members/members_edit_list.inc");
 
elseif ($mode ==  "members_edit"):
require( "$adminpath/include/members/members_edit.inc");
 
elseif ($mode ==  "members_edited"):
require( "$adminpath/include/members/members_edited.inc");

elseif ($mode ==  "members_deleted"):
require( "$adminpath/include/members/members_deleted.inc");

/*
 Begin Member Submission includes
*/

elseif ($mode ==  "members_sub_list"):
require( "$adminpath/include/members/members_sub_list.inc");

elseif ($mode ==  "members_sub_edit"):
require( "$adminpath/include/members/members_sub_edit.inc");

elseif ($mode ==  "members_sub_added"):
require( "$adminpath/include/members/members_sub_added.inc");

elseif ($mode ==  "members_sub_deleted"):
require( "$adminpath/include/members/members_sub_deleted.inc");

endif;

?>

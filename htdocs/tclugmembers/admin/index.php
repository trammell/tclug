<?
$path = "$DOCUMENT_ROOT";
include("include/auth.inc");
require("$path/include/shared.inc.php");
include("$path/include/lib.inc.php");

$TITLE = "$sitename Admin";
require( "$head");
include("$adminpath/include/login_check.inc");
?>
<p>
<B>Welcome to the Admin Section</B>

<P>Please choose and option below to begin your administration.

<UL>
<LI><A HREF="<?php print("$path_to_admin/$authadmin_script");?>">Authors Admin</A></LI>
<LI><A HREF="<?php print("$path_to_admin/$membersadmin_script");?>">Members Admin</A></LI>
</UL>
<?
include("$foot");
?>

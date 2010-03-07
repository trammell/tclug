<?
$TITLE = "$sitename Admin : Authors : Add New User";
include("$head");

print ("
<p>
<b>Add a new user:</b><br>
<a href=\"$path_to_admin/$authadmin_script\">Go back to admin</a>
<p>
<form action=\"$path_to_admin/$authadmin_script?mode=added_article\" method=\"post\">
<TABLE WIDTH=100% CELLPADDING=0 CELLSPACING=0 BORDER=0>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>Name:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td  VALIGN=TOP>
<input class=textbox type=\"text\" name=\"name\" size=\"40\">
	</td>
   </tr>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>URL:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td  VALIGN=TOP>
<input class=textbox type=\"text\" name=\"url\" size=\"40\"><br>
	</td>
   </tr>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>Email:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"email\" size=\"40\"><br>
	</td>
   </tr>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>Status:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td VALIGN=TOP>
<SELECT class=textbox NAME=\"status\"><OPTION>Author<OPTION>Editor<OPTION>Admin</SELECT>
	</td>
   </tr>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>Username:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"login\" size=\"40\"><br>
	</td>
   </tr>
   <tr>
	<td ALIGN=Right VALIGN=TOP >
<p><b>Password:</b>&nbsp;&nbsp;&nbsp;&nbsp;
	</td>
	<td VALIGN=TOP>
<input class=textbox type=\"password\" name=\"newpass\" size=\"40\"><br>
	</td>
   </tr>
   <tr>
	<td>
	&nbsp;
	</td>
	<td>
$button
	</td>
   </tr>
</TABLE>
<input type=\"hidden\" name=\"date\" value=\"$datetime\">
<input type=\"hidden\" name=\"active\" value=\"yes\">
<input type=\"hidden\" name=\"bio\" value=\"\">
</form>
<blockquote>
<p><i>Date is: $nicedate</i>
</blockquote>
   ");
include("$foot");
?>

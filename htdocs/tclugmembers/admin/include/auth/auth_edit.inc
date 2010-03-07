<?
 
$news_query = mysql_query("select * from $authorstable where artnr=\"$item\"") or die(mysql_error());
$row  =  mysql_fetch_array($news_query);
        $record_number=$row["artnr"];
        $name=$row["name"];
        $bio=$row["bio"];
        $auth_level=$row["status"];
        $email=$row["email"];
        $url=$row["url"];
        $date=$row["date"];
        $active=$row["active"];
        $login=$row["user"];
        $oldpass=$row["password"];
        $listening=$row["listening"];
        $reading=$row["reading"];
        $thinking=$row["thinking"];

$TITLE="$sitename Admin : Edit : $name";
include("$head");

include("$adminpath/include/login_check.inc");
print ("
<p>
<b>Edit Author Info:</b><br>
<a href=\"$path_to_admin/$authadmin_script\">Go back to admin</a><BR><BR>

<form action=\"$path_to_admin/$authadmin_script?mode=change&item=$item\" method=\"post\">
<TABLE WIDTH=100% CELLPADDING=2 CELLSPACING=2 BORDER=0>
   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Name:
	</TD>
	<TD VALIGN=TOP>
<input class=textbox type=\"text\" name=\"name\" size=\"40\" value=\"$name\">
	</TD>
   </TR>
   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Bio:
	</TD>
	<TD VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"bio\" COLS=70 ROWS=5 WRAP=PHYSICAL>$bio</TEXTAREA>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Hearing:<br>
	</TD>
	<TD VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"listening\" COLS=70 ROWS=5 WRAP=PHYSICAL>$listening</TEXTAREA>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Reading:
	</TD>
	<TD VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"reading\" COLS=70 ROWS=5 WRAP=PHYSICAL>$reading</TEXTAREA>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Thinking:
	</TD>
	<TD VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"thinking\" COLS=70 ROWS=5 WRAP=PHYSICAL>$thinking</TEXTAREA>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
URL:
	</TD>
	<TD VALIGN=TOP>
<input class=textbox type=\"text\" name=\"url\" size=\"40\" value=\"$url\"><br>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Email:
	</TD>
	<TD VALIGN=TOP>
<input class=textbox type=\"text\" name=\"email\" value=\"$email\" size=\"40\"><br>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Status:
	</TD>
	<TD VALIGN=TOP>
<SELECT class=textbox NAME=\"status\"><OPTION>$auth_level<OPTION>Author<OPTION>Editor<OPTION>Admin</SELECT>
	</TD>
   </TR>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Username:
	</TD>
	<TD VALIGN=TOP>
<input class=textbox type=\"text\" name=\"login\" value=\"$login\" size=\"40\"><br>
	</TD>
   </TR>
	<tr>
	  <td>
		&nbsp;
	  </td>
	  <td>
		<p>
		Leave blank to keep current password.
		  <br>
		Complete the password field to change the password.
	  </td>
	</tr>

   <TR>
	<TD ALIGN=Right VALIGN=TOP>
<p>
Password:
	</TD>
	<TD VALIGN=TOP>
<input class=textbox type=\"password\" name=\"newpass\" size=\"40\"><br>
	</TD>
   </TR>
   <TR>
	<TD>
&nbsp;
	</TD>
	<TD>
$button
	</TD>
   </TR>
</TABLE>
<input type=\"hidden\" name=\"oldpass\" value=\"$oldpass\">
<input type=\"hidden\" name=\"active\" value=\"yes\">
<input type=\"hidden\" name=\"date\" value=\"$date\">
</form>
<blockquote>
<i>Today is: $nicedate</i>
</blockquote>
   ");
include("$foot");
?>

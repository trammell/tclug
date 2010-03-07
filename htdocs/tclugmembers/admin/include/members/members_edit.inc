<?
$news_query = mysql_query("select * from $memberstable where artnr=\"$mid\"") or die(mysql_error());
$row  =  mysql_fetch_array($news_query);
        $mid=$row["artnr"];
        $name=$row["name"];
        $bio=$row["bio"];
        $status=$row["status"];
        $email=$row["email"];
        $showemail=$row["showemail"];
        $url=$row["url"];
        $date=$row["date"];
        $active=$row["active"];
        $login=$row["user"];
        $oldpass=$row["password"];

$TITLE="$sitename Admin : Edit : $name";

 
include("$head");

print ("
<p>
<b>Edit Member Info:</b><br>
<a href=\"$path_to_admin/$membersadmin_script\">Back to Admin</a>
<p>

<TABLE WIDTH=100% CELLPADDING=2 CELLSPACING=2 BORDER=0>
<form action=\"$path_to_admin/$membersadmin_script?mode=members_edited&mid=$mid\" method=\"post\">

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Name
	  </td>
	  <td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"name\" size=\"40\" value=\"$name\">
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Bio
	  </td>
	  <td VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"bio\" COLS=40 ROWS=5 WRAP=PHYSICAL>$bio</TEXTAREA>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
URL
	  </td>
	  <td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"url\" size=\"40\" value=\"$url\"><br>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Email
	  </td>
	  <td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"email\" value=\"$email\" size=\"40\"><br>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Status:
	  </td>
	  <td VALIGN=TOP>
<SELECT class=textbox NAME=\"status\"><OPTION>Member<OPTION>President<OPTION>Vice-Pres.<OPTION>Secretary</SELECT>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Active:
	  </td>
	  <td VALIGN=TOP>
<SELECT class=textbox NAME=\"active\"><OPTION>Yes<OPTION>No</SELECT>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Username:
	  </td>
	  <td VALIGN=TOP>
<input class=textbox type=\"text\" name=\"login\" value=\"$login\" size=\"40\"><br>
	  </td>
	</tr>
       <tr>
          <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Show Email:
          </td>
          <td WIDTH=475 VALIGN=TOP>
<SELECT class=textbox NAME=\"showemail\">
  <OPTION>$showemail
  <OPTION>Yes
  <OPTION>Converted
  <OPTION>No
</SELECT>
          </td>
        </tr>


	<tr>
	  <td align=right>
<b>Note:</b>
	  </td>
	  <td>


<p>
Only fill in the Password field if changing the user password
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP >
<p>
Password
	  </td>
	  <td VALIGN=TOP>
<input class=textbox type=\"password\" name=\"newpass\" size=\"40\"><br>
	  </td>
	</tr>

	<tr>
	  <td>
<input type=\"hidden\" name=\"oldpass\" value=\"$oldpass\">
<input type=\"hidden\" name=\"date\" value=\"$datetime\">
	  </td>
	  <td>
$button
	  </td>
	</tr>
</TABLE>

</form>
<blockquote>
<i>Today is $nicedate</i>
</blockquote>
	");
include("$foot");
?>

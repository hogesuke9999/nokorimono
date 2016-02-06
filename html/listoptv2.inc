<?php
// print("ページ = " . $_POST["PAGE"] . "<br>");
// print("OPT1   = " . $_POST["OPT1"] . "<br>");
// print("OPT2   = " . $_POST["OPT2"] . "<br>");
// print("OPT3   = " . $_POST["OPT3"] . "<br>");

$CHKOPT1[$_POST["OPT1"]] = " checked";
$CHKOPT2[$_POST["OPT2"]] = " checked";
$CHKOPT3[$_POST["OPT3"]] = " checked";

print("<h1>残り物 表示オプション変更</h1>\n");

print("<form method=\"POST\" action=\"index.php\">\n");

print("<table border=1>\n");

print("<tr>\n");
print("<td>賞味期限</td>\n");
print("<td>\n");
print("<input type=\"radio\" name=\"OPT1\" value=\"0\"" . $CHKOPT1[0] . ">すべて表示<br>\n");
print("<input type=\"radio\" name=\"OPT1\" value=\"1\"" . $CHKOPT1[1] . ">過ぎているものを表示<br>\n");
print("<input type=\"radio\" name=\"OPT1\" value=\"2\"" . $CHKOPT1[2] . ">過ぎていないものを表示<br>\n");
print("</td>\n");
print("</tr>\n");

print("<tr>\n");
print("<td>在庫</td>\n");
print("<td>\n");
print("<input type=\"radio\" name=\"OPT2\" value=\"0\"" . $CHKOPT2[0] . ">すべて表示<br>\n");
print("<input type=\"radio\" name=\"OPT2\" value=\"1\"" . $CHKOPT2[1] . ">なくなっているものを表示<br>\n");
print("<input type=\"radio\" name=\"OPT2\" value=\"2\"" . $CHKOPT2[2] . ">あるものを表示<br>\n");
print("</td>\n");
print("</tr>\n");

print("<tr>\n");
print("<td>表示順</td>\n");
print("<td>\n");
print("<input type=\"radio\" name=\"OPT3\" value=\"0\"" . $CHKOPT3[0] . ">登録順<br>\n");
print("<input type=\"radio\" name=\"OPT3\" value=\"1\"" . $CHKOPT3[1] . ">購入日順<br>\n");
print("<input type=\"radio\" name=\"OPT3\" value=\"2\"" . $CHKOPT3[2] . ">賞味期限順<br>\n");
print("</td>\n");
print("</tr>\n");

print("</table>\n");

print("<hr>");

print("<input type=\"submit\" value=\"表示オプション更新\" name=\"BTN\">\n");
print("<input type=\"hidden\" name=\"PAGE\" value=\"0\">");
print("</form>\n");
?>

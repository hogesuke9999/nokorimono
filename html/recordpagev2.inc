<?php
print("<h1>残り物 登録</h1>\n");

print("<form method=\"POST\" action=\"index.php\">");
print("<table border=\"1\">");
print("<tr>");
print("<td>購入日</td>");
print("<td>");
print("<input typr=\"text\" name=\"BuyDate1\" size=\"4\">年");
print("<input typr=\"text\" name=\"BuyDate2\" size=\"2\">月");
print("<input typr=\"text\" name=\"BuyDate3\" size=\"2\">日");
print("</td>");
print("</tr>");

print("<tr>");
print("<td>賞味期限</td>");
print("<td>");
print("<input typr=\"text\" name=\"LimitDate1\" size=\"4\">年");
print("<input typr=\"text\" name=\"LimitDate2\" size=\"2\">月");
print("<input typr=\"text\" name=\"LimitDate3\" size=\"2\">日");
print("<br>");
print("(賞味期限のない場合は、空欄にしておいてください)");
print("</td>");
print("</tr>");

print("<tr>");
print("<td>アイテム名</td>");
print("<td><input typr=\"text\" name=\"ItemName\" size=\"64\"></td>");
print("</tr>");

print("<tr>");
print("<td>個数</td><td><input typr=\"text\" name=\"ItemCount\"></td>");
print("</tr>");

print("<tr>");
print("<td>単位</td>");
print("<td>");

$SQL = "select ItemUnitNameCode, ItemUnitName from ItemUnitName;";
$result = DBexec($SQL);

print("<select name=\"ItemUnitNameCode\">\n");
for ($i = 0 ; $i < pg_numrows($result) ; $i++) {
	print("<option value=\"" . htmlspecialchars(pg_result($result, $i, 0)) . "\">");
	print(htmlspecialchars(pg_result($result, $i, 1)) . "\n");
}
print("</select>\n");

print(" / 新規登録の場合:");
print("<input typr=\"text\" name=\"ItemUnitName\" size=\"8\">");
print("</td>");
print("</tr>");

print("</table>");

print("<hr>");

print("<input type=\"submit\" name=\"BTN\" value=\"登録\">");
print("<input type=\"submit\" name=\"BTN\" value=\"キャンセル\">");

print("<input type=\"hidden\" name=\"OPT1\" value=\"" . $_POST["OPT1"] . "\">");
print("<input type=\"hidden\" name=\"OPT2\" value=\"" . $_POST["OPT2"] . "\">");
print("<input type=\"hidden\" name=\"PAGE\" value=\"" . $_POST["PAGE"] . "\">");

print("</form>");

?>

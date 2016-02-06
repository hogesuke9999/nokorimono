<?php

// 最大表示数の決定
function MAXCOUNT($OPT1, $OPT2) {
	$SQL  = "select count(*) from ZAIKO";
	$NXT  = " where";
	
	switch($OPT1) {
		case	"1":
			$SQL .= " ${NXT} LimitDate < current_date";
			$NXT  = " and";
			break;
	
		case	"2":
			$SQL .= " ${NXT} LimitDate >= current_date";
			$NXT  = " and";
			break;
	}
	
	switch($OPT2) {
		case	"1":
			$SQL .= " ${NXT} ItemCount <= 0";
			break;
	
		case	"2":
			$SQL .= " ${NXT} ItemCount > 0";
			break;
	}

	$result = DBexec($SQL);
	return pg_result($result, 0, 0);
}

// 登録処理
//  入力: BuyDate1, BuyDate2, BuyDate3 : 購入日
//       LimitDate1, LimitDate2, LimitDate3 : 消費期限日
//       ItemUnitName : 単位名
//       ItemUnitNameCode : 単位名コード
//       ItemName : 商品名
//       ItemCount : 商品個数
//  出力: なし

function RECORD($ItemName, $ItemCount, $BuyDate1, $BuyDate2, $BuyDate3, $LimitDate1, $LimitDate2, $LimitDate3) {
//	print "LimitDate1 = " . $LimitDate1 . "<br>\n";
//	print "LimitDate2 = " . $LimitDate2 . "<br>\n";
//	print "LimitDate3 = " . $LimitDate3 . "<br>\n";
	if(!is_numeric($BuyDate1))   return "登録できませんでした(BuyDate1が不適切です(" . $BuyDate1 . "))";
	if(!is_numeric($BuyDate2))   return "登録できませんでした(BuyDate2が不適切です(" . $BuyDate2 . "))"; 
	if(!is_numeric($BuyDate3))   return "登録できませんでした(BuyDate3が不適切です(" . $BuyDate3 . "))";
//	if(!is_numeric($LimitDate1)) return "登録できませんでした(LimitDate1が不適切です(" . $LimitDate1 . "))";
//	if(!is_numeric($LimitDate2)) return "登録できませんでした(LimitDate2が不適切です(" . $LimitDate2 . "))";
//	if(!is_numeric($LimitDate3)) return "登録できませんでした(LimitDate3が不適切です(" . $LimitDate3 . "))";
	if(!is_numeric($ItemCount))  return "登録できませんでした(ItemCountが不適切です)";

// 単位名の登録処理
	if($_POST["ItemUnitName"] != ""){
		$SQL = "select ItemUnitNameCode from ItemUnitName where ItemUnitName = '" . pg_escape_string($_POST["ItemUnitName"]) . "';";
		$result = DBexec($SQL);
	
		if(pg_numrows($result) == 0) {
//      単位名が登録されていない場合
			$SQL = "insert into ItemUnitName (ItemUnitName)  values('" . pg_escape_string($_POST["ItemUnitName"]) . "');";
			$result = DBexec($SQL);
			$SQL = "select ItemUnitNameCode from ItemUnitName where ItemUnitName = '" . pg_escape_string($_POST["ItemUnitName"]) . "';";
			$result = DBexec($SQL);
			$ItemUnitNameCode = pg_result($result, 0, 0);
		} else {
// 	    単位名が既に登録されている場合
			$ItemUnitNameCode = pg_result($result, 0, 0);
		}
	} else {
		$ItemUnitNameCode = $_POST["ItemUnitNameCode"] ;
	}

// 登録処理
	$SQL  = "insert into ZAIKO (BuyDate, LimitDate, ItemName, ItemCount, ItemUnitNameCode)";
	$SQL .= " values('${BuyDate1}-${BuyDate2}-${BuyDate3}', '${LimitDate1}-${LimitDate2}-${LimitDate3}', '" . pg_escape_string($_POST["ItemName"]) . "', " .  pg_escape_string($_POST["ItemCount"]) . ", ${ItemUnitNameCode});";
	$result = DBexec($SQL);
}


// 修正処理
//  入力: ZAIKO_No  : 対象アイテム番号
//       ItemCount : 変更後の値
//  出力: なし

function MODIFY($ZAIKO_No, $ItemCount) {
	if(!is_numeric($ItemCount))   return "更新できませんでした(ItemCountが不適切です)";
	$SQL  = "Update ZAIKO";
	$SQL .= " set ItemCount = " . pg_escape_string($ItemCount);
	$SQL .= " where ZAIKO_No = " . pg_escape_string($ZAIKO_No) . ";";
//	print($SQL . "<br>\n");
	$result = DBexec($SQL);
}

?>

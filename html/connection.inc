<?php
// データベースへの接続
function DBconnect($DBNAME) {
	$DBCONN = pg_connect("host=adis-postgresql01 port=5432 dbname=$DBNAME user=www");
	if ($DBCONN == "false") {
		print("データベースに接続できませんでした。");
		exit ;
	}
	return $DBCONN ;
}

// データベースの切断
function DBclose() {
  pg_close();		// データベースとの接続切断
}

// データベースの実行
function DBexec($SQL) {
  $result = pg_query($SQL);
  if ($result == false) {
    printf("SQL:\"$SQL\"の実行に失敗しました。");
    exit;
  }
  return $result ;
}
?>

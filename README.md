# DxUnit
DxLib + UnitTestの環境基本設定
以前作ったものがバージョンアップで動かなくなったので作り直し

## 前提
jenkinsサーバには  
https://github.com/ynws/jenkinsCCI  
を使用している

## 個別設定
このリポジトリをベースに新規に作成する場合、ビルドシェルの修正が必要

UnitTest.shの以下の行のDxUnitを正しいリポジトリ名に書き換える

```
cd /var/jenkins_home/workspace/DxUnit/
...
gcovr -r ~/workspace/DxUnit/MainLib --xml --output=Coverage.xml .
```

## jenkins設定
* ビルドシェル
    sh UnitTest.sh
* カバレッジレポート対象
    build/Coverage.xml
* テスト結果集計対象
    build/testresult.xml

## 済
* Dxlibサンプル動かす
* サンプルをクラス分離
* GoogleTestを入れる
* GoogleTest走行
* jenkinsでUnitTest
* jenkinsでcoverage表示

## TODO
* Releaseビルド
* x64ビルド
* GitHubブランチ監視でjenkinsビルド

* Dxlib使用ソースのテスト
    -> というか、Dxlib関数使ってるクラスはテスト対象とすべきなのか？
    環境依存コードは別個所にまとめておきたい

+ Main
    環境依存。例えばDxlib使うとか、別の画像ライブラリ使うとかは
    ここで切り替える。ソース量少ない
    メインロジックはMainLib呼ぶだけ
+ MainLib
    環境無依存のロジック
+ UnitTest
    MainLibのテスト

### UI部分をどう切り替える？
* 案1
    LibにUI用関数群のインターフェースをもつobjを渡す
    -> なんかダサい
* 案2
    ちゃんとMVCで作る
    M = lib
    V = dxlib
    C = ?

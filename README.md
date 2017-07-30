# DxUnit
DxLib + UnitTestの環境基本設定
以前作ったものがバージョンアップで動かなくなったので作り直し

## 前提
jenkinsサーバには  
https://github.com/ynws/jenkinsCCI  
を使用している

VisualStudioにGoogleTestAdapterを導入済み

## 個別設定
このリポジトリをベースに新規に作成する場合、ビルドシェルの修正が必要

UnitTest.shの以下の行のDxUnitを正しいリポジトリ名に書き換える

```
cd /var/jenkins_home/workspace/DxUnit/
...
gcovr -r ~/workspace/DxUnit/MainLib --xml --output=Coverage.xml .
```

## jenkins設定
### 基本設定
* ビルドするブランチ
    とりあえず、全対象で。本当はmaster用と開発用で分けるべき。今回はテストなので1つで
* SCMポーリング
    // 2minごと
    H/2 * * * *
### ビルド
* ビルドシェル
    sh UnitTest.sh
## ビルド後の処理
* JUnitテスト結果の集計
    build/testresult.xml
* Coberture カバレッジレポートの集計
    build/Coverage.xml
* Step Counter
    - LIB `**/*.cpp`
        除外: `UnitTest/*`
    - TEST `UnitTest/*.cpp`
* 未解決タスクの集計
    - 集計対象 `**/*.cpp`
    (現状あまり役に立ってないのでいらないかも。大規模になって、TODOコメント増えたら考える)

## 済
* Dxlibサンプル動かす
* サンプルをクラス分離
* GoogleTestを入れる
* GoogleTest走行
* jenkinsでUnitTest
* jenkinsでcoverage表示
* GitHubブランチ監視でjenkinsビルド
    -> ポーリングで。
* jenkinsの時間がずれているので直す
* カバレッジ計測対象から、GoogleTestコードを除外

## TODO
* Dxlib依存部の切り出し
    -> IO関係の処理を分離。本番ではDxlibを呼び、テストではMockを呼ぶ

### Dxlibコードの分離について
環境依存コードは別個所にまとめておきたい

+ Main
    環境依存。例えばDxlib使うとか、別の画像ライブラリ使うとかは
    ここで切り替える。ソース量少ない
    メインロジックはMainLib呼ぶだけ
+ MainLib
    環境無依存のロジック
    IO関係は他クラスに任せる
+ UnitTest
    MainLibのテスト
    IO関係はGoogleMockで


.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

FAQ
================

Q1: コンパイルエラー: SoftPWM.h: ファイルまたはディレクトリが見つかりません？
--------------------------------------------------------------------------------------------

「コンパイルエラー: SoftPWM.h: ファイルまたはディレクトリが見つかりません」というエラーが表示された場合、 ``SoftPWM`` ライブラリがインストールされていないことを意味します。

必要なライブラリ「SoftPWM」および「IRLremote」をインストールする方法は :ref:`ar_install_library` を参照してください。


Q2: avrdude: stk500_getsync() 試行10回中10回: 同期せず: resp=0x6e？
-------------------------------------------------------------------------------------

ボードとポートが正しく選択された後、アップロードボタンをクリックすると以下のメッセージが表示され続ける場合。

.. code-block::

    avrdude: stk500_recv(): プログラマが応答していません
    avrdude: stk500_getsync() 試行1回中10回: 同期せず: resp=0x00
    avrdude: stk500_recv(): プログラマが応答していません
    avrdude: stk500_getsync() 試行2回中10回: 同期せず: resp=0x00
    avrdude: stk500_recv(): プログラマが応答していません
    avrdude: stk500_getsync() 試行3回中10回: 同期せず: resp=0x00

この時点で、ESP32 CAMが抜かれていることを確認する必要があります。

ESP32-CAMとArduinoボードは、同じRX（受信）およびTX（送信）ピンを共有しています。したがって、コードをアップロードする際には、競合や潜在的な問題を避けるためにまずESP32-CAMを切断する必要があります。

.. image:: img/unplug_cam.png
    :width: 400
    :align: center

.. _stt_android:

Q3: AndroidデバイスでSTT機能を使用する方法は？
------------------------------------------------------------------------

STT機能を使用するためには、Androidモーバイルデバイスがインターネットに接続されており、 **Googleサービスコンポーネント** がインストールされている必要があります。

以下の手順に従ってください。

#. ``Zeus_Car.ino`` ファイルのAPモードをSTAモードに変更してください。

    * ``zeus-car-main/Zeus_Car`` ディレクトリにある ``Zeus_Car.ino`` ファイルを開きます。
    * APモード関連のコードをコメントアウトし、STAモード関連のコードのコメントを解除し、自宅のWi-Fiの ``SSID`` と ``PASSWORD`` を入力します。

        .. code-block:: arduino

            /** Wifiモード、SSID、パスワードを設定 */
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "Zeus_Car"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * このコードを保存し、正しいボード(Arduino Uno)とポートを選択して、 **Upload** ボタンをクリックしてR3ボードにアップロードしてください。

#. Google Playで ``google`` を検索し、以下に示すアプリを見つけてインストールします。

    .. image:: img/google_voice.png

#. コードに書かれているものと同じWi-Fiにモバイルデバイスを接続します。

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. 以前にSunFounder Controllerで作成したコントローラを開き、 |app_connect| ボタンを使って ``Zeus_Car`` に接続します。

    .. image:: img/app_connect.png
        :width: 500
        :align: center

#. |app_run| ボタンをクリックした後、 |app_speech_m| ウィジェットをタップ&ホールドします。聞き取り中であることを示すプロンプトが表示されます。車を動かすための次のコマンドを話します。

    * ``stop``: 車の動きをすべて停止できます。
    * ``pasue``: この機能はStopと基本的に同じですが、車の頭部が元々設定された方向を向いていない場合、設定された方向にゆっくりと動きます。
    * ``forward``
    * ``backward``
    * ``left forward``
    * ``left backward``
    * ``right forward``
    * ``right backward``
    * ``move left``
    * ``move right``
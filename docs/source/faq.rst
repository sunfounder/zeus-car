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
Wi-Fiチャンネルを変更する方法
----------------------------------

2.4GHz Wi-Fi帯域には、1から13までのチャンネルがあります。ESP32は1から11までのチャンネルをサポートしています。同じチャンネルで動作する他のデバイスが干渉を引き起こす場合があり、それが接続の問題につながる可能性があります。この問題を軽減するために、チャンネルを変更してみてください。デフォルトでは、チャンネルは1に設定されています。新しいチャンネルを選択する際には、1～2チャンネル飛ばして設定することを推奨します。例えば、現在のチャンネルが1の場合、まずチャンネル3を試し、それでも信号が悪い場合はチャンネル5に進みます。

.. note::

   Wi-Fi チャンネルの変更には、ESP32 CAM ファームウェア **1.4.1** 以降が必要です。詳しくは :ref:`update_firmware` を参照してください。

#. ESP32 CAM をアダプターに挿したまま、Zeus Car の電源を入れます。

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. ESP32 CAM を起動するには、モードスイッチを **Run** の位置に合わせ、**Reset** ボタンを押して R3 ボードを再起動します。

   .. image:: img/zeus_run123.jpg
      :width: 600

#. モバイル端末 (タブレットまたはスマートフォン) の利用可能なネットワーク一覧から ``Zeus_Car-XXXXXX`` を探し、パスワード ``12345678`` を入力して接続します。``XXXXXX`` は ESP32 CAM の MAC アドレスの下 6 桁で、ホットスポット名は車ごとに異なります。

   .. note::

        * 現在は Zeus Car のホットスポットに接続しているため、インターネットには接続できません。ネットワークの切り替えを求められたら「接続を維持」を選んでください。

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. モバイル端末の Web ブラウザで ``http://192.168.4.1`` を開き、ESP32 CAM の設定ページを表示します。

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: 設定ページは ESP32 CAM のファームウェアのバージョンによって異なります。バージョン A (ファームウェア 1.4.x) は Wi-Fi と OTA の設定が 1 つのページにまとまっています。バージョン B (ファームウェア 1.5.x 以降) には **Base**、**AP**、**WIFI**、**Camera**、**OTA** のタブがあります。表示されている画面に合わせて手順を選んでください。

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**バージョン A** (ファームウェア 1.4.x)

   5. **Wi-Fi AP Channel** のセクションで別のチャンネルを選び、**Confirm** ボタンをクリックします。

      * 既定のチャンネルは 1 です。変更するときは 1〜2 チャンネルずつ飛ばしてください (例: チャンネル 1 から 3、必要なら 5 へ)。

      .. image:: img/faq_cam_ota_channel.png
         :width: 400

   #. デバイスをリセットするよう求める確認ダイアログが表示されます。**Confirm** をクリックします。

      .. image:: img/faq_cam_ota_reset.jpg
         :width: 400

   #. R3 ボードの **Reset** ボタンを押して ESP32 CAM を再起動します。これで Zeus Car は通常どおり使用できます。

      .. image:: img/zeus_run123.jpg
         :width: 600

**バージョン B** (ファームウェア 1.5.x 以降)

   5. サイドメニューの **AP** をクリック (または画面下部の **AP** タブをタップ) し、**AP Channel** の一覧から別のチャンネルを選びます。

      * 既定のチャンネルは 1 です。変更するときは 1〜2 チャンネルずつ飛ばしてください (例: チャンネル 1 から 3、必要なら 5 へ)。

      .. image:: img/faq_change_channel.jpg
         :width: 400

   #. ページ上部に「Reboot to take effect.」というバナーが表示されたら **REBOOT** をクリックします。これで Zeus Car は通常どおり使用できます。

.. _update_firmware:

ESP32 CAMのファームウェアを更新する方法
-----------------------------------------

ESP32 CAMのファームウェアを更新するには、以下の詳細な手順に従ってください：

#. ESP32 CAM をアダプターに挿したまま、Zeus Car の電源を入れます。

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. ESP32 CAM を起動するには、モードスイッチを **Run** の位置に合わせ、**Reset** ボタンを押して R3 ボードを再起動します。

   .. image:: img/zeus_run123.jpg
      :width: 600

#. ファームウェアファイルをダウンロードします。

   * `ESP32 CAM ファームウェアの最新リリース <https://github.com/sunfounder/ai-camera-firmware/releases/latest>`_ を開きます。ページ上部に現在のファームウェアのバージョンが表示されています。
   * **Assets** の一覧から ``ai-camera-firmware.vX.X.X-ota.bin`` をダウンロードします。同じ一覧にある ``-factory.bin`` はライターでモジュールを書き込むためのファイルで、このアップデートでは使用しません。

   .. image:: img/faq_firm_download.png
      :width: 600

#. モバイル端末を Zeus Car の Wi-Fi ネットワークに接続します。

   * ネットワーク名 (SSID) は ``Zeus_Car-XXXXXX`` です。``XXXXXX`` は ESP32 CAM の MAC アドレスの下 6 桁で、パスワードは ``12345678`` です。
   * 「インターネットに接続されていません」という警告が表示されたら、**「接続を維持」** を選んでください。

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. モバイル端末の Web ブラウザで ``http://192.168.4.1`` を開き、ESP32 CAM の設定ページを表示します。

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: このページの OTA アップデート画面は 2 種類のいずれかになります。ファームウェアのバージョンに応じて、バージョン A (前者) またはバージョン B (後者) が表示されます。表示されている画面に合わせて手順を選んでください。

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**バージョン A** (ファームウェア 1.4.x)

   6. OTA ページでファームウェアファイルを選び、アップデートを開始します:

      * 先ほどダウンロードした ``ai-camera-firmware.vX.X.X-ota.bin`` を選び、**Add** をクリックします。
      * **Update** ボタンをクリックしてアップデートを開始し、完了するまで待ちます。

      .. image:: img/faq_ota_a.png
         :width: 700

   #. アップデートが完了すると、Zeus Car のホットスポット名は ``AI Camera-XXXXXX`` に変わり、パスワードは ``12345678`` のままです。R3 ボードの **Reset** ボタンを押すと車が名前を登録し直し、ホットスポットは ``Zeus_Car-XXXXXX`` に戻ります。

**バージョン B** (ファームウェア 1.5.x 以降)

   6. **OTA** ページで、表示されている現在のファームウェアのバージョンを確認します。

      .. image:: img/faq_upgrade.jpg
         :width: 400
         :align: center

   #. **Upgrade Firmware** をタップし、ファームウェアファイルを選んで、アップデートが完了するまで待ちます:

      * **Upgrade Firmware** ボタンをタップし、先ほどダウンロードした ``ai-camera-firmware.vX.X.X-ota.bin`` を選びます。
      * アップデートはすぐに始まり、通常 1〜2 分かかります。完了したら **CONFIRM** を選んで Zeus Car を再起動します。

      .. image:: img/faq_ota_b.png
         :width: 700

   #. アップデートが完了すると、Zeus Car のホットスポット名は ``AI Camera-XXXXXX`` に変わり、パスワードは ``12345678`` のままです。R3 ボードの **Reset** ボタンを押すと車が名前を登録し直し、ホットスポットは ``Zeus_Car-XXXXXX`` に戻ります。

.. _upload_zeus_code:

``zeus-car.ino`` コードをアップロードする方法
-----------------------------------------------

デフォルトでは、Zeus CarのUno R3ボードには必要なファームウェアがプリロードされており、APPを介して操作できます。他のコードがR3ボードに書き込まれている場合でも、デフォルトのファームウェアに戻し、:ref:`quick_start` プロセスを続行するには、以下の手順に従ってコードを再アップロードしてください：

#. USBケーブルを使用してArduinoをコンピュータに接続します。ESP32-CAMとArduinoボードは同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードする際には、ESP32-CAMを最初に取り外して、競合や潜在的な問題を回避する必要があります。
   
   .. image:: img/unplug_cam.png
        :width: 400

#. 以下のリンクから必要なファームウェアをダウンロードします：
        
   * :download:`R3 Board Firmware File <https://github.com/sunfounder/zeus-car/releases/download/1.4.5/zeus-car-1.4.5.zip>`

#. ダウンロードしたzipファイルを解凍し、 ``update-arduino-firmware.bat`` ファイルをダブルクリックして実行します。

   .. image:: img/faq_firmware_file.png

#. Zeus CarのArduino Uno用に該当する番号（例： ``1`` ）を入力し、 **Enter** を押して更新を開始します。

   .. note::

     * 正しいCOMポートが表示されない場合、またはどれが正しいか不明な場合は、他のUSBデバイスをコンピュータから取り外し、ローバーのみを接続してください。  
     * ``avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX`` のようなエラーが発生した場合は、最初の手順としてESP32-CAMを取り外してください。

   .. image:: img/faq_firmware_port.png

#. しばらくすると、新しいコードがZeus CarのUno R3ボードに正常にアップロードされます。複数回試行しても成功しない場合は、 ``update-arduino-firmware-with-bootloader.bat`` を実行してください。

   .. image:: img/faq_firmware_finish.png

.. _ap_to_sta:

ホームWiFiを使用してZeus Carを制御する方法
-------------------------------------------------
デフォルトでは、Uno R3にはAPPモードに設定されたコードがプリロードされています。このモードでは、Zeus Carがホットスポットを放送し、モバイルデバイスを接続してSunFounder Controller APPを介して制御できます。

自宅の Wi-Fi で車を操作したい場合は、ESP32 CAM を自宅のネットワークに参加させることができます。カメラは AP + STA のデュアルモードで動作し続けるため、Zeus Car のホットスポットも引き続き利用できます:

#. Zeus Car の電源を入れます。ESP32 CAM を起動するには、モードスイッチを **Run** の位置に合わせ、**Reset** ボタンを押して R3 ボードを再起動します。

   .. image:: img/zeus_run123.jpg
      :width: 600

#. モバイル端末を Zeus Car の Wi-Fi ネットワークに接続します。

   * ネットワーク名 (SSID) は ``Zeus_Car-XXXXXX`` です。``XXXXXX`` は ESP32 CAM の MAC アドレスの下 6 桁で、パスワードは ``12345678`` です。
   * 「インターネットに接続されていません」という警告が表示されたら、**「接続を維持」** を選んでください。

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. モバイル端末の Web ブラウザで ``http://192.168.4.1`` を開き、ESP32 CAM の設定ページを表示します。

   .. image:: img/faq_ota_home.jpg
      :width: 400

#. サイドメニューの **WIFI** をクリック (または画面下部の **WIFI** タブをタップ) し、自宅 Wi-Fi の名前とパスワードを入力します。

   * **STA SSID** に自宅 Wi-Fi の名前を入力します (スキャンした一覧から選ぶこともできます)。**STA password** にパスワードを入力します。
   * **CONFIRM** をタップして設定を保存します。保存されると、ページに「Success, Restart to apply.」と表示されます。
   * 再起動後、**Base** ページの **IP Address** に、ルーターがカメラに割り当てた IP アドレスが表示されます。

   .. image:: img/faq_set_sta.jpg
      :width: 400

#. ESP32 CAM を再起動します: ページの **Reboot** をクリックするか、R3 ボードの **Reset** ボタンを押します。ESP32 CAM は自宅 Wi-Fi に接続し、同時に Zeus Car のホットスポットも維持します。

   .. note::

      ESP32 CAM ファームウェア **1.5.4** 以降では、カメラは AP + STA のデュアルモードで動作し、シリアルコマンド ``MODE`` は無視されます。そのため、R3 のスケッチで ``WIFI_MODE``、``SSID``、``PASSWORD`` を変更してもカメラが STA モードに切り替わることはありません。上記の手順で自宅 Wi-Fi を設定してください。

#. モバイルデバイス（タブレットやスマートフォン）がホームWiFiネットワークに接続されていることを確認します。

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. SunFounder Controller Appを開き、"+"アイコンをタップして新しいコントローラーを作成します。「Zeus Car」のプリセットを選択し、名前を入力するか、「Confirm」をタップして進みます。

   .. image:: img/app_preset.jpg
        :width: 600

#. アプリが自動的にZeus Carを検索します。しばらくすると、 「Connected Successfully」 というプロンプトが表示されます。

   .. image:: img/app_edit.jpg
        :width: 600
    
#. 次に、|app_run| ボタンをタップすると、カメラのライブ映像を視聴し、提供されたウィジェットを使用してローバーを制御できるようになります。

   .. image:: img/app_run123.png
        :width: 600 
    
カメラを反転する方法  
---------------------------

SunFounder Controllerを使用しているときにカメラ映像が上下逆さまになっている場合、アプリ内で簡単に修正できます。以下の手順に従ってください：  

1. 右上の |app_edit| ボタンをタップします。  

   .. image:: img/faq_edit.png  
        :width: 500 

2. **camera** ボタンをクリックしてポップアップを開きます。 **Inverted** スイッチをオンに切り替えます。  

   .. image:: img/faq_inverted.png  
        :width: 500  

3. 設定を保存します。  

   .. image:: img/faq_save.png  
        :width: 500 

4. コントロール画面に戻り、|app_run| ボタンをクリックします。  

   .. note::  

        時々、カメラ映像が表示されない場合があります。その場合は、コントローラーを一時停止してから再度再生ボタンをクリックしてください。  

   .. image:: img/faq_run.png  
        :width: 500  


コンパイルエラー: SoftPWM.h: ファイルまたはディレクトリが見つかりません？
--------------------------------------------------------------------------------------------

「Compilation error: SoftPWM.h: No such file or directory」というプロンプトが表示された場合、それは ``SoftPWM`` ライブラリがインストールされていないことを意味します。

必要なライブラリのインストールについては、:ref:`ar_install_lib` を参照してください。

avrdude: stk500_getsync() 試行10回中10回: 同期せず: resp=0x6e？
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

AndroidデバイスでSTT機能を使用する方法は？
------------------------------------------------------------------------

STT機能を使用するためには、Androidモーバイルデバイスがインターネットに接続されており、 **Googleサービスコンポーネント** がインストールされている必要があります。

以下の手順に従ってください。

#. Zeus Car とモバイル端末の両方がインターネットに接続できるよう、Zeus Car を自宅 Wi-Fi に接続します。:ref:`ap_to_sta` の手順で、ESP32 CAM の設定ページに自宅 Wi-Fi を保存してください。``Zeus_Car.ino`` のコードを変更したり再アップロードしたりする必要はありません。
#. Google Playで ``google`` を検索し、以下に示すアプリを見つけてインストールします。

    .. image:: img/google_voice.png

#. モバイル端末を同じ自宅 Wi-Fi ネットワークに接続します。

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. 以前にSunFounder Controllerで作成したコントローラを開き、 |app_connect| ボタンを使って Zeus Car に接続します。

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

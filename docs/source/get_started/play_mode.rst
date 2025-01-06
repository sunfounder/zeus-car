.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _ar_play_mode:


実際の操作モード
======================

実際の操作モードとは、工場でArduinoボードにコードを事前にアップロードし、Zeus CarはオンにするだけでAPPやリモコンでリモート制御できるモードのことです。

* :ref:`play_app_control` : あなたの携帯やタブレットにSunFounder Controllerをインストールする必要があります。これにより、ジョイスティックウィジェットを使用してZeus Carを全方向に制御したり、音声制御を行ったりすることができます。そして、何よりも、APP上でZeus Carによって撮影されたリアルタイムの映像ストリームを見ることができます。

* :ref:`play_remote_control` : 簡単なリモコンも装備しています。Zeus Carをオンにするだけで、リモコンで制御することができます。これは、Zeus Carの制御の楽しさをできるだけ早く体験したいユーザーにとって良い選択です。

.. note::

    このキットのコードパッケージはこちらです。

    * :download:`SunFounder Zeus Car Kit for Arduino <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

    Arduinoに異なるコードをアップロードした後、 **プレイモード** に戻りたい場合は、まず :ref:`ar_install_library` を行い、次にパス ``zeus-car-main\Zeus_Car`` 下にある ``Zeus_Car.ino`` ファイルをArduinoボードにアップロードする必要があります。

.. toctree::
    :maxdepth: 3

    app_control
    remote_control

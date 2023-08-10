.. _install_arduino:


Arduino IDE 2.0のダウンロードとインストール
=============================================================

Arduino IDEはArduino Integrated Development Environmentとして知られており、Arduinoプロジェクトを完成させるために必要なソフトウェアのサポートをすべて提供します。これは、Arduinoチームが提供する、Arduino用に特別に設計されたプログラミングソフトウェアであり、Arduinoボードにプログラムを書き込んでアップロードすることができます。

Arduino IDE 2.0はオープンソースのプロジェクトであり、堅牢な前身であるArduino IDE 1.xから大きなステップアップとなっており、リニューアルされたUI、改良されたボード＆ライブラリマネージャ、デバッガ、オートコンプリート機能などが搭載されています。

このチュートリアルでは、Windows、Mac、LinuxのコンピュータにArduino IDE 2.0をダウンロードしてインストールする方法を紹介します。

要件
-------------------

* Windows - Win 10以上、64ビット
* Linux - 64ビット
* Mac OS X - バージョン10.14：「Mojave」以上、64ビット

Arduino IDE 2.0のダウンロード
-------------------------------------------

#. |link_download_arduino| を訪問してください。

#. お使いのOSバージョンのIDEをダウンロードしてください。

    .. image:: img/arduino/sp_001.png

インストール
------------------------------

* :ref:`ide_windows`
* :ref:`ide_macos`
* :ref:`ide_linux`

.. _ide_windows:

Windows
^^^^^^^^^^^^^

#. ダウンロードした ``arduino-ide_xxxx.exe`` ファイルをダブルクリックして実行します。

#. ライセンス契約を読み、同意します。

    .. image:: img/arduino/sp_002.png

#. インストールオプションを選択します。

    .. image:: img/arduino/sp_003.png

#. インストール場所を選択します。ソフトウェアはシステムドライブ以外のドライブにインストールすることをおすすめします。

    .. image:: img/arduino/sp_004.png

#. その後、完了します。 

    .. image:: img/arduino/sp_005.png

.. _ide_macos:

macOS
^^^^^^^^^^^^^^^^

ダウンロードした ``arduino_ide_xxxx.dmg`` ファイルをダブルクリックし、指示に従って **Arduino IDE.app** を **Applications** フォルダにコピーします。数秒後にArduino IDEが正常にインストールされたことが確認できます。

.. image:: img/arduino/macos_install_ide.png
    :width: 800

.. _ide_linux:

Linux
^^^^^^^^^^^^

LinuxシステムでArduino IDE 2.0をインストールするチュートリアルは、以下のリンクを参照してください：https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux

IDEの起動
--------------

#. Arduino IDE 2.0を初めて開くと、Arduino AVR Boards、組み込みライブラリ、および他の必要なファイルが自動的にインストールされます。

    .. image:: img/arduino/sp_901.png

#. さらに、ファイアウォールやセキュリティセンターが何度かポップアップして、デバイスドライバをインストールするかどうかを尋ねてくるかもしれません。すべてのドライバをインストールしてください。

    .. image:: img/arduino/sp_104.png

#. これで、あなたのArduino IDEが準備完了です！

    .. note::
        ネットワークの問題やその他の理由で一部のインストールが完了しなかった場合、Arduino IDEを再度開くと、残りのインストールが完了します。すべてのインストールが完了した後、VerifyまたはUploadをクリックしない限り、Outputウィンドウは自動的に開きません。
.. _play_app_control:

Controlled by APP
=========================

Zeus Car出厂时已经预上传了代码，让你可以直接用手机APP来控制它。

但在控制前，你需要先在手机/平板上下载APP(SunFounder Controller)，然后连上Zeus Car发出的局域网，最后在SunFounder Controller上创建属于你的遥控器来控制Zeus Car。


Quick Guide
---------------------


#. Install `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ from **APP Store(iOS)** or **Google Play(Android)**.

#. 启动Zeus Car。

    * 由于Zeus Car Shield上板载过放保护电路，在第一次使用或者是拔出电池线时会认为电压过低，从而激活保护电路。
    * 所以当你将电源开关拨向ON，此时电源指示灯将不会点亮，你需要插入Type-C线大概5秒左右。

            .. image:: img/zeus_charge.jpg

    * 若电源指示灯点亮，说明保护电路已关闭，可以正常使用了。此时再看下电量指示灯，如果两个电量指示灯都关闭，请继续插入Type-C的线给Zeus Car充电。

        .. image:: img/zeus_power.jpg

    * 此时Zeus Car正常启动，能从车底看到Cyan color的光。

        .. image:: img/zeus_car.jpg

    * 如果出现的是黄色的光，说明启动不成功，请按下复位按钮来让R3板内的代码重新运行。

        .. image:: img/zeus_reset_button.jpg

    * 如果还是黄色的光，请确认下这个按钮是否已拨向右边（运行模式）。

        .. image:: img/zeus_run_upload.jpg



#. Connect to ``Zeus_Car`` WLAN.

    * Find ``Zeus_Car`` on the WLAN of the mobile phone (tablet), enter the password ``12345678`` and connect to it.

    .. image:: img/app_wlan.png

    * The default connection mode is AP mode. So after you connect, there will be a prompt telling you that there is no Internet access on this WLAN network, please choose to continue connecting.

    .. image:: img/app_no_internet.png

#. Create a controller.

    * 打开SunFounder Controller之后，点击 + 图标来添加遥控器

        .. image:: img/app1.png

    * There are preset controllers for some products in the Preset section, 这里我们选择Zeus Car.

    .. image:: img/app_preset.png

    * 你也许可能想给它一个名字，之后点击Confirm.

    .. image:: img/app_name.png
    
    * 现在你已经进入到遥控器内部，里面已经有设定的几个部件。点击右上角 |app_save| 按钮。

    .. image:: img/app_edit.png

    * 接下来你需要通过 |app_connect| 按钮来让Zeus Car和你的设备连接上。等待几秒，将出现Zeus_Car(IP), 点击它来连接。

    .. image:: img/app_auto_connect.png

    .. note::
        如果很久没有出现，请确认你的Wi-Fi是否有连接到Zeus_Car。

#. Run the Controller.

    * 出现"Connected Successfully"提示后，点击 |app_run| 按钮。
    * 摄像头拍摄的画面将在APP上出现，and now you can control your Zeus Car with these widgets.

    .. image:: img/app_run.png

    Here are the functions of the widgets.

    * :ref:`app_compass_cali`: 开启罗盘校准。
    * **Stop(F)**: 停止小车的所有动作。
    * **Set Heading(I)**: 用手将小车放置一个方向之后，点击这个键来将此时车头的朝向作为小车移动的前方，这可以让你快速指定一个方向，而不是通过其他按键将小车慢慢旋转到那个方向。
    * :ref:`app_drift`: 启动漂移功能
    * :ref:`app_move`: 控制小车全向移动。
    * :ref:`app_speech_control`: 切换到语音控制模式
    * :ref:`app_line_track`: 切换到循线模式
    * :ref:`app_follow`: 切换到跟随模式
    * :ref:`app_avoid`: 切换到避障模式
    * :ref:`app_rotate_drift`: 用来控制车头方向。

.. _app_compass_cali:

Calibration(E)
--------------------------

点击 |app_cali_e| 按钮来开启罗盘校准功能。

将Zeus Car放在地面上，罗盘校准功能开启后，小车将开始逆时针旋转来校准，预计1分钟左右停止。如果它转动超过2分钟，说明此地的磁场比较复杂，建议换个地方再校准下。



.. _app_drift:

Drift Enable(J)
---------------------

点击 |app_drift_j| 按钮来启动漂移功能。

* 此时，当你逆时针滑动 |app_rotate_q| 小部件时，Zeus Car会以逆时针漂移。松手后，小车将停在原位。

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

* 若顺时针滑动 |app_rotate_q| 小部件，Zeus Car将随着顺时针漂移。松手后，小车将停在原位。

.. image:: img/zeus_drift_right.jpg
    :width: 600
    :align: center


.. _app_move:

全向移动(k)
---------------

往各个方向滑动 |app_move_k| 小部件，将会让Zeus Car往相应的方向移动。

.. image:: img/joystick_move.png
    :align: center

每滑动一次，小车移动一次，如果一直未松手，小车将一直移动。

.. image:: img/zeus_move.jpg


.. _app_speech_control:

Speech(M)
-------------------

.. warning::
    Android设备无法使用语音控制功能，因为它使用的是谷歌在线的语音识别引擎，所以如果要使用该语音控制功能，需要在Android移动设备上安装谷歌服务组件，并且需要连接网络。
    而iOS设备使用的是离线的语音识别引擎，不需要联网，AP 和 STA 模式连接都可以。

    如果需要在Android设备使用语音控制，请到后面编程环节。

在SunFounder Controller中，你还可以用语音来控制Zeus Car. 就是对着你的移动设备说一些指令，移动设备检测到之后，将这个指令发给Zeus Car，然后Zeus Car将执行设定好的动作。

现在按住 |app_speech_m| 小部件，说以下任意指令看下将发生什么。

* ``stop``: 可以停止小车所有动作。
* ``pasue``: 功能和Stop基本一致，但如果此时小车的车头朝向不是原先设定的，它将慢慢移动到设定方向。
* ``forward``
* ``backward``
* ``left forward``
* ``left backward``
* ``right forward``
* ``right backward``
* ``move left``
* ``move right``

    小车接收到上述8个指令后，它将按相应的方向一直移动，除非接收到 ``stop`` 或 ``pasue`` 指令。

    .. image:: img/zeus_move.jpg

* ``turn left``: 会让小车以车身为中心左转45°，然后它将根据前一状态来前进或停止，如果是上一状态是停止，左转45°后，它停止；如果是前进，左转完之后将前进。


    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

* ``turn right``: 会让小车以车身为中心右转45°，同样将根据前一状态来前进或停止。

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center




.. _app_line_track:

Line(N)
--------------

点击 |app_line_n| 小部件切换到循线模式。

Zeus Car的循线模式有两种，一种是车头总是朝着移动方向，另外一种是它的头是固定方向的。这里选用的是第二种模式，所以你会看到Zeus Car将侧着循线前进。

但在让它循线前，你需要先校准Omni 灰度模块以及贴好轨道，具体步骤如下：

#. 贴好轨道

    在Omni灰度模块上有8个灰度传感器，每两个传感器之间的距离在2~3cm之间，为了让Omni灰度传感器至少能有2个传感器同时检测到黑线，所以你贴的轨道至少要3cm的宽度，弯道角度不要小于90°。

    .. image:: img/map.png
        :width: 800

#. 校准Omni Grayscale module。

        因为不同的地板灰度值不同，导致Omni灰度模块目前设定好的灵敏度有差异，你需要在使用前校准。建议在地板颜色变化较大时，都需要校准。

    * 将Zeus Car放在白色地面上，拧动电位器直到灰度传感器的指示灯刚好点亮。

        .. image:: img/zeus_line_calibration.jpg

    * 现在让侧边两个灰度传感器刚好位于黑线和白线之间的交界处，慢慢拧动电位器直到信号指示灯刚好熄灭。

        .. image:: img/zeus_line_calibration1.jpg（缺图）

    * 你可以在黑线和白线上反复移动，确定灰度传感器的灯在黑线与白线之间的交界处时熄灭，在白色表面时亮起，说明就校准好了。


#. 将Zeus Car放在你贴好的轨道，点击 |app_line_n| 小部件，它就能跟着轨道前进。

#. 由于灰度传感器对环境的要求较高，如果循线效果不理想（脱轨），建议多校准几次。

.. _app_follow:

Follow(O)
------------

点击 |app_follow_o| 小部件切换到跟随模式。

超声波检测正前方的障碍物（20cm），检测到就跟随前进。两侧的红外避障模块用来让小车跟随左转或者右转，但是在使用前需要校准这两个模块（15cm）。

#. 校准红外避障模块。

    * 将一个障碍物放在离红外避障模块15cm左右的地方。
    * 模块上有2个电位器，一个是校准发送功率，一个是校准接收频率，通过调节这两个电位器能调节它的有效距离。
    * 所以你可以先调一个电位器，如果在15cm时，模块上的信号灯刚刚好点亮，说明调节成功；如果发现检测不到，你可以调节另外一个电位器，信号灯刚好点亮就行。

        .. image:: img/zeus_ir_avoid.jpg

    * 按照同样的方法校准另外一个避障模块。

#. 将Zeus放在桌面或地面上，让它跟着你的手或其他的障碍物移动。

.. _app_avoid:

Avoid(p)
------------------------

点击 |app_avoid_p| 小部件来切换到避障模式，但请确认你已先参考 :ref:`app_follow` 校准2个避障模块。

* Zeus会向前移动。
* 超声波检测正前方的障碍物，检测到左转。
* 左侧避障模块检测到障碍物，小车右转，右侧避障模块检测到障碍物，小车左转。



.. _app_rotate_drift:

Control the Drection(Q)
-------------------------------

* 当 |app_drift_j| 按钮开启时， |app_rotate_q| 小部件是用来让Zeus Car进行左右漂移。

* 当 |app_drift_j| 小部件关闭时， |app_rotate_q| 小部件是用来控制小车转向。

    * 以逆时针滑动 |app_rotate_q| 小部件，小车也随着逆时针转向，松手后小车车头将回到一开始设置的方向。

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

    * 以顺时针滑动 |app_rotate_q| 小部件, 小车也随着顺时针转向，松手后小车车头将回到一开始设置的方向。

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center




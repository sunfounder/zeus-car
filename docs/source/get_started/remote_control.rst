.. _play_remote_control:

Control by Remote
==========================

用遥控器控制Zeus Car将会比较简单，只需要将Zeus Car开机，然后直接按下遥控器上的按键就行。这种方法稳定性强，不容易受外界干扰，但可能控制没那么灵活。

Quick Guide
--------------------

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

#. 按下遥控器上的不同按钮来操控小车。

    .. image:: img/remote_control.jpg
        :width: 800

    * **Stop**: 可以停止小车所有动作。
    * :ref:`ir_compass_cali`: 开启罗盘校准。
    * :ref:`ir_line_track`：切换到循线模式。
    * :ref:`ir_follow`：切换到跟随模式
    * :ref:`ir_avoid`：切换到避障模式
    * :ref:`drift`: 向左漂移/右漂移。
    * **Set Heading**：用手将小车放置一个方向之后，按下这个键来将此时车头的朝向作为小车移动的前方，这可以让你快速指定一个方向，而不是通过其他按键将小车慢慢旋转到那个方向。
    * :ref:`rotate_left/right`: 向左/右旋转
    * :ref:`ir_move`：你可以用这些方向箭头来让小车往8个方向移动。
    * **Pause**：功能和Stop基本一致，但如果此时小车的车头朝向不是原先设定的，它将慢慢移动到设定方向。

.. _ir_compass_cali:

Compass Calibration
--------------------------

按下 |ir_mute| 来启罗盘校准功能。因为每个地方磁场不一样，所以在使用前先校准。

将Zeus Car放在地面上，然后按下遥控器上的按键，小车将开始逆时针旋转来校准，预计1分钟左右停止。如果它转动超过2分钟，说明此地的磁场比较复杂，建议换个地方再校准下。

.. _ir_line_track:

Line Track
--------------

按下 |ir_play| 来切换到循线模式。

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

.. _ir_follow:

Follow
------------

按下 |ir_backward| 来切换到跟随模式。

超声波检测正前方的障碍物（20cm），检测到就跟随前进。两侧的红外避障模块用来让小车跟随左转或者右转，但是在使用前需要校准这两个模块（15cm）。

#. 校准红外避障模块。

    * 将一个障碍物放在离红外避障模块15cm左右的地方。
    * 模块上有2个电位器，一个是调节发射功率，一个是调节发射频率，通过调节这两个电位器能调节它的有效距离。
    * 所以你可以先调一个电位器，如果在15cm时，模块上的信号灯刚刚好点亮，说明调节成功；如果发现检测不到，你可以调节另外一个电位器，信号灯刚好点亮就行。

        .. image:: img/zeus_ir_avoid.jpg

    * 按照同样的方法校准另外一个避障模块。

#. 将Zeus放在桌面或地面上，让它跟着你的手或其他的障碍物移动。

.. _ir_avoid:

Obstacle Avoidance
------------------------

按下 |ir_forward| 来切换到避障模式，但请确认你已先参考 :ref:`ir_follow` 校准2个避障模块。

* Zeus会向前移动。
* 超声波检测正前方的障碍物，检测到左转。
* 左侧避障模块检测到障碍物，小车右转，右侧避障模块检测到障碍物，小车左转。

.. _drift:

Drift Left/Right
---------------------

通过 |ir_minus| and |ir_plus| 让小车向左/右漂移。

* 按下 |ir_minus| 键，小车将向左漂移

.. image:: img/zeus_drift_left.jpg
    :width: 600
    :align: center

* 按下 |ir_plus| ，小车将向右漂移。

.. image:: img/zeus_drift_right.jpg
    :width: 600
    :align: center

* 如果漂移前是停止状态，按下一次 |ir_minus| 或 |ir_plus| 键，Zeus向左或向右漂移90°。
* 如果漂移前是移动的，按下按键之后，Zeus Car将向左或向右漂移90°，然后平移直到你按下其他按键。

.. _ir_move:

8向移动
---------------

* 通过数字键1~9来让Zeus Car向8个方向移动。由于在前进和后退函数中添加了重置车头方向代码，所以你可以让它以任意方向作为正前方，而不是以之前用 |ir_0| 按钮设定好方向作为正前方。

.. image:: img/remote_control_move.jpg

.. _rotate_left/right:

Rotate Left/Right
------------------

* 按下 |ir_return| 一次， 会让小车以车身为中心左转45°。然后它将根据前一状态来前进或停止，如果是上一状态是停止，左转45°后，它停止；如果是前进，左转完之后将前进。

.. image:: img/zeus_turn_left.jpg
    :width: 600
    :align: center

* 同理，按下 |ir_usd| 一次， 会让小车以车身为中心右转45°，然后它将根据前一状态来前进或停止。

.. image:: img/zeus_turn_right.jpg
    :width: 600
    :align: center

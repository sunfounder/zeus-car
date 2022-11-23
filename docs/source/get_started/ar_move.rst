1. Basic Movements
========================

在这个项目中，你将学习如何将让Zeus Car前后移动，左右旋转以及停止。

* 前后移动，左右平移。

    .. image:: img/ar_fwlr.jpg

* 对角平移
    .. image:: img/ar_fblr.jpg

* 左右旋转
    .. image:: img/ar_turn_lr.jpg

**How to do?**

#. 先确认这个按钮是否拨向左边（上传模式）。

        .. image:: img/zeus_upload.jpg（缺图）

#. Open the ``1_basic_move.ino`` file under the path of ``zeus-car-main\examples\1_basic_move``. Or copy this code into Arduino IDE.

<代码>

#. 启动Zeus Car。

    * 由于Zeus Car Shield上板载过放保护电路，在第一次使用或者是拔出电池线时会认为电压过低，从而激活保护电路。
    * 所以当你将电源开关拨向ON，此时电源指示灯将不会点亮，你需要插入Type-C线大概5秒左右。

            .. image:: img/zeus_charge.jpg

    * 若电源指示灯点亮，说明保护电路已关闭，可以正常使用了。此时再看下电量指示灯，如果两个电量指示灯都关闭，请继续插入Type-C的线给Zeus Car充电。

        .. image:: img/zeus_power.jpg

#. 此时Zeus Car将向前后移动，左右旋转，左右平移，




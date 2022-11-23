2. Omni Move
==========================


在这个项目中，你将学习如何将让Zeus Car往0度，45度，90度，135度，180度，225度，270度，315度移动。

如果忽略底上的摩擦力以及结构误差，它的路线应该是个八边形，并最终回到原点。


.. code-block::

    void carMove(int16_t angle, int8_t power)

* ``angle``: The direction you want the car to move。以小车车头作为0度位置，以逆时针方向增加角度。
* ``power``: 移动功率，范围是-100% ~ 100%。 ``power``为正时，小车前进，反之则后退。

**How to do?**

#. 先确认这个按钮是否拨向左边（上传模式）。

        .. image:: img/zeus_upload.jpg（缺图）

#. Open the ``2_omni_move.ino`` file under the path of ``zeus-car-main\examples\2_omni_move``. Or copy this code into Arduino IDE.

<代码>

#. 将电源开关拨向ON来启动Zeus Car.

    .. image:: img/zeus_power.jpg

#. 此时Zeus Car将往8个方向移动。

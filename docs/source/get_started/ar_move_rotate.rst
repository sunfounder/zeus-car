3. Move and Rotate
======================

在这个项目中，你将学习给Zeus Car的移动函数 ``carMove()`` 增加一个旋转功率 ``rot`` 之后，移动效果会发生怎样的变化。

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: the direction you want the car to move。以小车车头作为0度位置，以逆时针方向增加角度。
* ``power``: 移动功率，范围是-100% ~ 100%。 ``power``为正时，小车前进，反之则后退。 
* ``rot``: 旋转功率，范围是-100% ~ 100%。 ``rot`` 为正时，小车逆时针转，反之则顺时针转。

如果 ``power`` 为0时， ``rot`` 不为0，Zeus Car将原地自转。旋转功率越大，自转速度越快。 ``rot`` 为正时，小车逆时针旋转，反之则顺时针旋转。

    .. image:: img/ar_rotate.png

如果 ``power`` 不为0，并且慢慢增加 ``rot``，你会发现Zeus Car将转弯前进，并且转弯角度会随着 ``rot`` 的增加而慢慢减小，到一定时候它将自转。

    .. image:: img/ar_rotate_forward.png

**How to do?**

#. 先确认这个按钮是否拨向左边（上传模式）。

        .. image:: img/zeus_upload.jpg（缺图）

#. Open the ``3_rotate_and_move.ino`` file under the path of ``zeus-car-main\examples\3_rotate_and_move``. Or copy this code into Arduino IDE.

<代码>

#. 将电源开关拨向ON来启动Zeus Car.

    .. image:: img/zeus_power.jpg

#. 此时Zeus Car将左转一下，然后右转回到原地。然后以转弯前进，并且转弯角度慢慢减小，到一定时候它将自转。

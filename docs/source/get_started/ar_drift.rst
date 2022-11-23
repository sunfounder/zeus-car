4. Drift
======================

在这个项目中，你将学习如何让Zeus Car漂移。Zeus Car的漂移是在移动函数 ``carMove()`` 中增加了漂移参数 ``drift``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: the direction you want the car to move。以小车车头作为0度位置，以逆时针方向增加角度。
* ``power``: 移动功率，范围是-100% ~ 100%。 ``power``为正时，小车前进，反之则后退。 
* ``rot``: 旋转功率，范围是-100% ~ 100%。 ``rot`` 为正时，小车逆时针转，反之则顺时针转。
* ``drift``: 默认为false, 当它为true 时，开启漂移模式。

所以 ``power`` 和 ``rot`` 值的不同会改变Zeus Car的漂移角度和方向。

.. image:: img/zeus_drift_left.jpg

**How to do?**

#. 先确认这个按钮是否拨向左边（上传模式）。

        .. image:: img/zeus_upload.jpg（缺图）

#. Open the ``4_drift.ino`` file under the path of ``zeus-car-main\examples\4_drift``. Or copy this code into Arduino IDE.

<代码>

#. 将电源开关拨向ON来启动Zeus Car.

    .. image:: img/zeus_power.jpg

#. 此时Zeus Car将前进0.5秒，再左漂90度，以此重复。你可以试着将 45（rot） 改成 改成其他值或者负数，看下漂移角度和方向如何变化。
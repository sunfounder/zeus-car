
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _update_firmware:

Updating the ESP32 CAM Firmware
=======================================

To ensure your device performs at its best and enjoys the latest features, we recommend checking and updating your ESP32 CAM firmware to the most recent version. Please follow the steps below to update your firmware.

#. Connect to the ``Zeus_Car`` Wi-Fi network:

   * On your mobile phone or tablet, go to your Wi-Fi settings and find the network named ``Zeus_Car``.
   * Enter the password ``12345678`` to connect.

   .. image:: img/firmware/SSID.png
      :width: 500
      
   .. note:: 

        The default connection mode is **AP mode**. After connecting, you may receive a warning that there is no internet access on this network. If so, choose to **"Stay connected"**.

        .. image:: img/app_no_internet.png
            :width: 500

#. Open a web browser and navigate to ``http://192.168.4.1`` to access the ESP32 CAM firmware update page.

   .. image:: img/firmware/OTAUpdate.jpg
      :width: 500

#. Check the current firmware version:

   * On the update page, you'll see the current firmware version displayed.
   * **If your version is 1.5.1 or higher**, your firmware is up to date, and no further action is needed (**you can skip following steps**).
   * **If your version is below 1.5.1**, please proceed with the following steps to update your firmware.

   .. image:: img/firmware/OTAversion.jpg
      :width: 500

#. Click here to download the latest firmware:

   * :download:`Zeus Car Firmware File <https://github.com/sunfounder/zeus-car/archive/refs/heads/1.5.zip>`

#. Then transfer the ``ai-camera-firmware.ino.1.5.1.bin`` file to your mobile phone or tablet.

   .. image:: img/firmware/selectBin.png
      :width: 500

#. On the firmware update page, click the button to select the firmware file.

   .. image:: img/firmware/OTASButton.jpg
      :width: 500

#. Upload and start the upgrade:

   * Choose the ``ai-camera-firmware.ino.1.5.1.bin`` file from your device.
   * Click **Upgrade** to begin the firmware update process.

   .. image:: img/firmware/OTASelect.jpg
      :width: 500

#. Wait for the upgrade to complete:

   * The upgrade process may take a few minutes. Please wait patiently until it's finished.
   * Once the current version number shows as **1.5.1**, the upgrade is successful.

   .. image:: img/firmware/OTAFinish.jpg
      :width: 500

#. After the update is complete, you can close the web page. Congratulations! Your ESP32 firmware is now up to date.


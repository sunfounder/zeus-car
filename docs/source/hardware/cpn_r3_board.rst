.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _cpn_uno:

Carte SunFounder R3
===========================

.. image:: img/uno_r3.jpg
    :width: 600
    :align: center

.. note::

    La carte SunFounder R3 est une carte microcontrôleur offrant quasiment les mêmes fonctionnalités que l’ `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, et les deux peuvent être utilisées de manière interchangeable.

La carte SunFounder R3 est basée sur le microcontrôleur ATmega328P (`datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Elle dispose de 14 broches d’entrée/sortie numériques (dont 6 peuvent être utilisées comme sorties PWM), 6 entrées analogiques, un résonateur céramique de 16 MHz (CSTCE16M0V53-R0), une connexion USB, une prise d’alimentation, un connecteur ICSP et un bouton de réinitialisation. Elle contient tout le nécessaire pour faire fonctionner le microcontrôleur ; il suffit de la connecter à un ordinateur via un câble USB ou de l’alimenter avec un adaptateur AC/DC ou une batterie pour commencer à l’utiliser.

**Paramètres Techniques**

.. image:: img/uno.jpg
    :align: center

* MICROCONTRÔLEUR : ATmega328P
* TENSION DE FONCTIONNEMENT : 5V
* TENSION D’ENTRÉE (RECOMMANDÉE) : 7-12V
* TENSION D’ENTRÉE (LIMITE) : 6-20V
* BROCHES D’E/S NUMÉRIQUES : 14 (0-13, dont 6 prennent en charge la sortie PWM (3, 5, 6, 9-11))
* BROCHES PWM : 6 (3, 5, 6, 9-11)
* BROCHES D’ENTRÉE ANALOGIQUE : 6 (A0-A5)
* COURANT CONTINU PAR BROCHE D’E/S : 20 mA
* COURANT CONTINU POUR LA BROCHE 3.3V : 50 mA
* MÉMOIRE FLASH : 32 KB (ATmega328P), dont 0.5 KB utilisés par le bootloader
* SRAM : 2 KB (ATmega328P)
* EEPROM : 1 KB (ATmega328P)
* FRÉQUENCE D’HORLOGE : 16 MHz
* LED_BUILTIN : 13
* LONGUEUR : 68.6 mm
* LARGEUR : 53.4 mm
* POIDS : 25 g
* Port I2C : A4 (SDA), A5 (SCL)

**Ressources Supplémentaires**

* `Arduino IDE <https://www.arduino.cc/en/software>`_
* `Référence du Langage Arduino <https://www.arduino.cc/reference/en/>`_
* :ref:`install_arduino_ide`
* `Fiche technique ATmega328P <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_

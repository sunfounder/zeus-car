.. note::  

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, d’Arduino et de l’ESP32 avec d’autres passionnés.  

    **Pourquoi nous rejoindre ?**  

    - **Support d’experts** : Obtenez de l’aide pour résoudre vos problèmes après-vente et relevez vos défis techniques grâce à notre communauté et notre équipe.  
    - **Apprenez & partagez** : Échangez des conseils et tutoriels pour perfectionner vos compétences.  
    - **Aperçus exclusifs** : Profitez d’un accès anticipé aux annonces de nouveaux produits et à des avant-premières exclusives.  
    - **Réductions spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.  
    - **Promotions et cadeaux festifs** : Participez à des jeux-concours et à des offres spéciales à l’occasion des fêtes.  

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !  

.. _install_arduino_ide:  

Téléchargement et installation d’Arduino IDE 2.0  
===================================================

L’Arduino IDE (Environnement de Développement Intégré) fournit tous les outils logiciels nécessaires à la réalisation d’un projet Arduino. Développé par l’équipe Arduino, cet IDE permet d’écrire des programmes et de les téléverser sur une carte Arduino.  

Arduino IDE 2.0 est un projet open-source qui représente une avancée majeure par rapport à son prédécesseur, Arduino IDE 1.x. Il propose une interface utilisateur modernisée, une gestion améliorée des cartes et des bibliothèques, un débogueur intégré, une fonction d’autocomplétion et bien d’autres fonctionnalités.  

Dans ce tutoriel, nous vous expliquerons comment télécharger et installer l’Arduino IDE 2.0 sur Windows, Mac et Linux.  

Configuration requise  
------------------------

* **Windows** - Windows 10 ou plus récent, 64 bits  
* **Linux** - 64 bits  
* **Mac OS X** - Version 10.14 "Mojave" ou plus récent, 64 bits  

Téléchargement d’Arduino IDE 2.0  
-----------------------------------

#. Rendez-vous sur |link_download_arduino|.  

#. Téléchargez l’IDE correspondant à votre système d’exploitation.  

    .. image:: img/arduino/sp_001.png  

Installation  
---------------

* :ref:`ide_windows`  
* :ref:`ide_macos`  
* :ref:`ide_linux`  

.. _ide_windows:  

Installation sous Windows  
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Double-cliquez sur le fichier ``arduino-ide_xxxx.exe`` téléchargé pour lancer l’installation.  

#. Lisez et acceptez le contrat de licence.  

    .. image:: img/arduino/sp_002.png  

#. Choisissez les options d’installation.  

    .. image:: img/arduino/sp_003.png  

#. Sélectionnez le répertoire d’installation. Il est recommandé d’installer le logiciel sur un disque autre que celui du système.  

    .. image:: img/arduino/sp_004.png  

#. Cliquez sur **Terminer** une fois l’installation achevée.  

    .. image:: img/arduino/sp_005.png  

.. _ide_macos:  

Installation sous macOS  
^^^^^^^^^^^^^^^^^^^^^^^^^^

Double-cliquez sur le fichier ``arduino_ide_xxxx.dmg`` téléchargé, puis suivez les instructions pour copier **Arduino IDE.app** dans le dossier **Applications**. Après quelques secondes, l’installation sera terminée.  

.. image:: img/arduino/macos_install_ide.png  
    :width: 800  

.. _ide_linux:  

Installation sous Linux  
^^^^^^^^^^^^^^^^^^^^^^^^^^

Pour les instructions d’installation d’Arduino IDE 2.0 sous Linux, veuillez consulter la documentation officielle :  
https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux  


Ouverture de l’IDE  
---------------------

#. Lors du premier lancement d’Arduino IDE 2.0, le logiciel installe automatiquement les cartes Arduino AVR, les bibliothèques intégrées et d’autres fichiers nécessaires.  

    .. image:: img/arduino/sp_901.png  

#. De plus, votre pare-feu ou votre logiciel de sécurité peut afficher des messages vous demandant d’installer certains pilotes. Veuillez accepter toutes les installations. 

    .. image:: img/arduino/sp_104.png  

#. Votre Arduino IDE est maintenant prêt à l’emploi !  

    .. note::  
        Si certaines installations échouent en raison de problèmes de connexion ou d’autres raisons, vous pouvez redémarrer l’IDE, et il terminera l’installation. La fenêtre Output ne s’ouvrira pas automatiquement une fois l’installation terminée, sauf si vous cliquez sur Verify ou Upload.  

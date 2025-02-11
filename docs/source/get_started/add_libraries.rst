.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi rejoindre notre communauté ?**

    - **Support d'experts** : Obtenez de l'aide de notre équipe et de notre communauté pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Profitez d’un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Bénéficiez de promotions exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _ar_install_lib:

Installer les bibliothèques requises
===============================================

**Qu'est-ce qu'une bibliothèque ?**

Une bibliothèque est un ensemble de fonctions prédéfinies et d’en-têtes facilitant et optimisant la programmation. Elle est généralement composée de deux fichiers principaux :

* **.h (Fichier d'en-tête)** : Contient les déclarations de fonctions, les définitions de macros et les constructeurs.
* **.cpp (Fichier source)** : Inclut l’implémentation des fonctions, la définition des variables et d’autres composants exécutables.

En ajoutant une bibliothèque à votre projet, vous pouvez appeler directement ses fonctions (ex. : ``#include <dht.h>``) au lieu de les coder vous-même. Cela rend votre code plus concis et plus lisible.

Bien qu'il soit possible d'écrire ses propres définitions de fonctions, l'utilisation de bibliothèques permet de gagner du temps et de réduire la complexité.

Certaines bibliothèques sont préinstallées avec l'IDE Arduino, tandis que d'autres doivent être installées manuellement. Voici comment installer les bibliothèques nécessaires à ce projet.

**Comment installer une bibliothèque ?**

.. note::

    Les instructions suivantes concernent **Arduino IDE 2.0**. Si vous utilisez Arduino IDE 1.x, veuillez consulter |link_install_library|.

Suivez ces étapes pour installer une bibliothèque :

1. Cliquez sur l’icône **Library Manager** dans la colonne de gauche de l’IDE Arduino.

   .. image:: img/arduino/ar_libr_manager.jpg

2. Recherchez la bibliothèque :

   * Une liste de bibliothèques disponibles s'affiche. Utilisez la barre de recherche pour trouver la bibliothèque que vous souhaitez installer.
   * Par exemple, pour installer la bibliothèque ``SoftPWM``, saisissez son nom et cliquez sur le bouton **INSTALL**.

   .. image:: img/arduino/ar_softpwm.png

3. Le processus d’installation prend généralement moins d’une minute. Une fois terminé, la bibliothèque affichera **INSTALLED** dans le gestionnaire de bibliothèques.

   .. image:: img/arduino/ar_install_success.png

4. Répétez les mêmes étapes pour installer la bibliothèque ``IRLremote``, en veillant à bien orthographier son nom.

   .. image:: img/arduino/ar_irlremote.png

5. Installez ensuite la bibliothèque ``ArduinoJson``.

   .. image:: img/arduino/ar_arduinojson.png

6. Enfin, recherchez et installez la bibliothèque ``SunFounder AI Camera``, qui est la dernière bibliothèque requise pour ce projet.

   .. image:: img/arduino/ar_aicamera.png

En suivant ces étapes, vous disposerez de toutes les bibliothèques nécessaires pour mener à bien votre projet.

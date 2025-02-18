# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
import time

# -- Project information -----------------------------------------------------

project = 'SunFounder Zeus Robot Car Kit for Arduino'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'

# -- sphinx_rtd_theme Theme options -----------------------------------------------------
html_theme_options = {
    'flyout_display': 'attached',
    'version_selector': False,
    'language_selector': False,
}

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']



html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js', # new
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]


rst_epilog = """

.. |ir_power| image:: /get_started/img/remote/ir_power.png
    :width: 40

.. |ir_mute| image:: /get_started/img/remote/ir_mute.png
    :width: 40

.. |ir_play| image:: /get_started/img/remote/ir_play.png
    :width: 40

.. |ir_backward| image:: /get_started/img/remote/ir_backward.png
    :width: 40

.. |ir_forward| image:: /get_started/img/remote/ir_forward.png
    :width: 40

.. |ir_minus| image:: /get_started/img/remote/ir_minus.png
    :width: 40

.. |ir_plus| image:: /get_started/img/remote/ir_plus.png
    :width: 40

.. |ir_0| image:: /get_started/img/remote/ir_0.png
    :width: 40

.. |ir_return| image:: /get_started/img/remote/ir_return.png
    :width: 40

.. |ir_usd| image:: /get_started/img/remote/ir_usd.png
    :width: 40

.. |app_connect| image:: /get_started/img/app/app_connect.jpg
    :width: 20

.. |app_save| image:: /get_started/img/app/app_save.jpg
    :width: 20

.. |app_run| image:: /get_started/img/app/app_run.png
    :width: 20

.. |app_avoid_p| image:: /get_started/img/app/app_avoid_p.png
    :width: 100
    
.. |app_cali_e| image:: /get_started/img/app/app_cali_e.png
    :width: 100
    
.. |app_drift_j| image:: /get_started/img/app/app_drift_j.png
    :width: 100

.. |app_follow_o| image:: /get_started/img/app/app_follow_o.png
    :width: 100

.. |app_heading_i| image:: /get_started/img/app/app_heading_i.png
    :width: 100

.. |app_line_n| image:: /get_started/img/app/app_line_n.png
    :width: 100

.. |app_move_k| image:: /get_started/img/app/app_move_k.png
    :width: 100

.. |app_rotate_q| image:: /get_started/img/app/app_rotate_q.png
    :width: 100

.. |app_speech_m| image:: /get_started/img/app/app_speech_m.png
    :width: 100

.. |app_stop_f| image:: /get_started/img/app/app_stop_f.png
    :width: 100

.. |app_camera| image:: /get_started/img/app/app_camera.png
    :width: 30

.. |app_edit| image:: /get_started/img/app/app_edit.jpg
    :width: 20

"""

# open link in a new window

rst_epilog += """
.. |link_german_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/de/latest/" target="_blank">Deutsch Online-Kurs</a>

.. |link_jp_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/ja/latest/" target="_blank">日本語オンライン教材</a>

.. |link_en_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/en/latest/" target="_blank">English Online-tutorials</a>

.. |link_fr_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/fr/latest/" target="_blank">Didacticiels en ligne en français</a>

.. |link_es_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/es/latest/" target="_blank">Tutoriales en línea en español</a>

.. |link_it_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/zeus-car/it/latest/" target="_blank">Tutorial online in italiano</a>

.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Arduino IDE 2.0.0 Page</a>


.. |link_install_library| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries" target="_blank">Installing Libraries</a>

.. |link_esp32cam_schematic| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/esp32_cam_sch.pdf" target="_blank">ESP32-CAM schematic diagram</a>

.. |link_cam_ov2640| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/ov2640_ds_1.8_.pdf" target="_blank">ov2640_ds_1.8</a>

.. |link_aithiner| raw:: html

    <a href="https://docs.ai-thinker.com/en/esp32-cam" target="_blank">Ai-Thinker</a>

.. |link_qmc6310_datasheet| raw:: html

    <a href="https://www.qstcorp.com/upload/pdf/202202/%EF%BC%88%E5%B7%B2%E4%BC%A0%EF%BC%8913-52-17%20QMC6310%20Datasheet%20Rev.C(1).pdf" target="_blank">QMC6310 Datasheet</a>

.. |link_ws2812_datasheet| raw:: html

    <a href="https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" target="_blank">WS2812B Datasheet</a>

.. |link_tcrt5000_datasheet| raw:: html

    <a href="https://datasheetspdf.com/pdf-file/377371/VishayTelefunken/TCRT5000/1" target="_blank">TCRT5000 Reflective Sensor</a>

.. |link_lm339_datasheet| raw:: html

    <a href="https://datasheetspdf.com/pdf-file/1055868/FairchildSemiconductor/LM339/1" target="_blank">LM339 Quad Comparator</a>

.. |link_74hc165_datasheet| raw:: html

    <a href="https://datasheetspdf.com/pdf-file/944867/NXP/74HC165/1" target="_blank">74HC165 Shift Register</a>

.. |link_zeus_code| raw:: html

    <a href="https://github.com/sunfounder/zeus-car" target="_blank">SunFounder Zeus Car Kit for Arduino - GitHub </a>


.. |link_sf_facebook| raw:: html

    <a href="https://bit.ly/raphaelkit" target="_blank">hier</a>

.. |link_Zeus_Car| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-zeus-car-robot-car-kit-compatible-with-arduino-uno-r3?_pos=1&_sid=10355f713&_ss=r" target="_blank">Kauflink für Zeus Car</a>

.. |link_Robot_Car_Kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-zeus-car-robot-car-kit-compatible-with-arduino-uno-r3?_pos=1&_sid=10355f713&_ss=r" target="_blank">Zeus Car</a>

"""

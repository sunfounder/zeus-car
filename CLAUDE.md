# CLAUDE.md — SunFounder Zeus Car Documentation

## Repository Overview

This is the **SunFounder Zeus Car Kit** documentation repository, built with **Sphinx** using the
**Read the Docs** theme. The documentation lives entirely under `docs/source/` as RST files.

- **GitHub**: https://github.com/sunfounder/zeus-car
- **Documentation**: https://docs.sunfounder.com/projects/zeus-car/en/latest/
- **Build system**: Sphinx (`docs/Makefile`, `docs/requirements.txt`)
- **License**: GPL-2.0
- **Product**: Arduino-based robot car kit with Mecanum wheels, ESP32-CAM FPV, obstacle
  avoidance, line tracking, IR remote control, and RGB lighting

> **Note**: The `main` branch contains the **Arduino firmware source code** (`.ino`, `.cpp`,
> `.h`). All documentation work happens on the `docs*` branches. The two are independent
> codebases — do not mix documentation changes with firmware code.

## Quick Start

```bash
pip install -r docs/requirements.txt
cd docs && make html
```

The `.gitignore` contains `build*` — **never read, edit, or commit anything under
`docs/build/`**. That folder is build output only.

## Branch & Language Architecture

`docs` is the **source of truth** (English). All other language branches are translations
that must mirror `docs` in file structure, toctrees, section counts, and RST directives
exactly — differing only in the natural language of their prose.

| Branch      | Language | `conf.py` setting |
|-------------|----------|--------------------|
| `docs`      | English  | `language = 'en'` (default) |
| `docs-de`   | German   | `language = 'de'` |
| `docs-es`   | Spanish  | `language = 'es'` |
| `docs-fr`   | French   | `language = 'fr'` |
| `docs-it`   | Italian  | `language = 'it'` |
| `docs-ja`   | Japanese | `language = 'ja'` |
| `main`      | (firmware — Arduino .ino/.cpp/.h) | — |

There is no git submodule — all content is self-contained within each branch.

## Sync Protocol: `docs` → Other Languages

When `docs` is updated, every other language branch must be brought into parity.
The check-list for each translation branch:

1. **File existence**: every `.rst` file under `docs/source/` that exists in `docs`
   must also exist in the translation branch.
2. **Toctrees**: every `.. toctree::` directive must list the same entries in the same order.
3. **Section structure**: headings, sub-headings, `.. note::`, `.. important::`,
   `.. code-block::`, `.. list-table::` directives must match present-for-present.
4. **Images & videos**: image paths and video embeds are shared across languages —
   do NOT change paths during translation. Add new images to the same relative paths as `docs`.
5. **RST anchors**: labels like `.. _quick_start:` must be identical across all languages
   (they are used for cross-references).
6. **Heading underlines**: `===` / `---` / `~~~` / `^^^` must be longer than the heading
   text (translations tend to be longer than English).
7. **Inline markup + CJK**: `**bold**`, `` `code` ``, `|subref|` followed by a CJK letter
   or `（` need a `\ ` escape (see Inline Markup and CJK Characters section below).

The only thing that should differ is the human-language prose.

## RST Heading Conventions

This is a hard rule for ALL rst files:

> **The underline (`===`, `---`, `~~~`, `^^^`) on the line immediately below a heading
> MUST be longer than the heading text itself.**

```
✅ Good:
A Very Long Section Title
==========================

✅ Good:
Short Title
------------

❌ Bad:
A Very Long Section Title
=========================

❌ Bad:
Short Title
-----------
```

### Heading hierarchy in use

| Level | Character | Used for |
|-------|-----------|----------|
| 1     | `=` | Document / chapter title |
| 2     | `-` | Section within a document |
| 3+    | `~` or `^` | Sub-sections (if needed) |

Examples from the codebase:

```rst
SunFounder Zeus Robot Car Kit for Arduino
===========================================================

Hardware
==================

1. Basic Movement
============================

Quick Start
--------------
```

## RST Style Rules

### Community ad note
Most RST files start with a `.. note::` block containing the Facebook community ad.
Translate the ad into the target language. Minor variations in ad presence (e.g.,
a file in one language having it while the English original doesn't) are acceptable —
don't add or remove ads to force alignment on this cosmetic item.

### Code blocks
Always specify the language:
```rst
.. code-block:: bash

.. code-block:: cpp

.. code-block:: python
```

### Cross-references
Use `:ref:` with anchor labels defined via `.. _label_name:`:
```rst
:ref:`quick_start`
:ref:`programming_arduino`
```
Labels must be identical across all language branches.

### Inline Markup and CJK Characters

RST inline markup — `**bold**`, `` `code` ``, ` ``code`` `, `|substitution|` — requires
the **closing delimiter** to be immediately followed by **whitespace, punctuation, or
end-of-line**. When translating to Japanese (or any CJK language), this rule is frequently
broken because:

- CJK characters are **letters**, not punctuation — they do NOT count as valid terminators
- Full-width punctuation like `，` `。` `：` `、` `）` IS recognized, but `（` (full-width
  left paren, Unicode Ps category) may NOT be recognized by all RST parsers

**Patterns that need `\ ` (backslash-escaped space) after the closing delimiter:**

| Pattern | Fix | Example |
|---------|-----|---------|
| `**text**CJK` | `**text**\ CJK` | `**not**compatible` → `**not**\ compatible` |
| `**text**（` | `**text**\ （` | `**Arduino**（互換）` → `**Arduino**\ （互換）` |
| `` `code`CJK `` | `` `code`\ CJK `` | same pattern |
| ` ``code``CJK ` | ` ``code``\ CJK ` | ` ``Zeus_Car``モデル` → ` ``Zeus_Car``\ モデル` |
| ` ``code``（ ` | ` ``code``\ （ ` | ` ``main``（ファームウェア）` → ` ``main``\ （ファームウェア）` |
| `|subref|CJK` | `|subref|\ CJK` | same pattern |
| `|subref|（` | `|subref|\ （` | `|link_sf_facebook|（クリック）` → `|link_sf_facebook|\ （クリック）` |

**Patterns that are safe (no fix needed):**

| Pattern | Reason |
|---------|--------|
| `**text**：` | Full-width colon is punctuation |
| `**text**，` | Full-width comma is punctuation |
| `**text**。` | Full-width period is punctuation |
| `**text**、` | Full-width enumeration comma is punctuation |
| `**text**）` | Full-width right paren is punctuation |

**Post-translation check-list for each file:**
1. Search for `**` followed by a CJK letter or `（` → add `\ ` escape
2. Search for `` ` `` or ` `` ` followed by a CJK letter or `（` → add `\ ` escape
3. Search for `|xxx|` followed by a CJK letter or `（` → add `\ ` escape
4. Do NOT add `\ ` after punctuation characters (`：，。、）`)

### Images
```rst
.. image:: img/zeus_car.jpg
    :width: 500
    :align: center
```
Images are stored in `docs/source/get_started/img/` and `docs/source/get_started/img/<subdir>/`.
Images are shared across languages — do NOT rename or translate image paths.

### Videos
Videos are stored in `docs/source/_static/video/` as MP4 files. Embed via:
```rst
.. raw:: html

    <source src="../_static/video/basic_movement.mp4" type="video/mp4">
```
Video paths and embed code are shared across languages — copy verbatim from `docs`.

## File Structure

```
docs/
├── Makefile
├── make.bat                  # Windows build script
├── requirements.txt          # sphinx, sphinx_rtd_theme, sphinx_copybutton
├── source/
│   ├── conf.py               # Language-specific (language = 'XX' differs per branch)
│   ├── index.rst             # Root toctree — homepage
│   ├── faq.rst               # FAQ (WiFi, firmware, code upload, speech control)
│   ├── _static/
│   │   ├── lang.js           # Client-side language detection & redirect
│   │   └── video/            # 10 MP4 tutorial videos
│   ├── _templates/
│   │   └── layout.html       # Custom Sphinx layout with SunFounder navbar
│   ├── get_started/
│   │   ├── get_started.rst   # Getting Started toctree
│   │   ├── assembly_instructions.rst
│   │   ├── play_mode.rst     # Quick play (app + IR remote)
│   │   ├── app_control.rst   # Mobile app control
│   │   ├── remote_control.rst # IR remote control
│   │   ├── programming_mode.rst
│   │   ├── download_code.rst
│   │   ├── install_arduino_ide.rst
│   │   ├── introduce_ide.rst
│   │   ├── add_libraries.rst
│   │   ├── ar_projects.rst   # Arduino projects toctree
│   │   ├── ar_move.rst       # Basic movement
│   │   ├── ar_omni_move.rst  # Omni-directional movement
│   │   ├── ar_move_rotate.rst
│   │   ├── ar_drift.rst
│   │   ├── ar_remote_control.rst
│   │   ├── ar_car_light.rst
│   │   ├── ar_compass.rst
│   │   ├── ar_move_field_centric.rst
│   │   ├── ar_hc165_and_ir_obstacle.rst
│   │   ├── ar_ultrasonic.rst
│   │   ├── ar_avoid.rst      # Obstacle avoidance
│   │   ├── ar_follow.rst     # Object following
│   │   ├── ar_grayscale.rst
│   │   ├── ar_line_track.rst
│   │   ├── ar_line_track_field_centric.rst
│   │   ├── ai_detection_from_app.rst
│   │   ├── ar_app_control.rst
│   │   ├── ar_app_control_plus.rst
│   │   └── img/              # Section-specific images (150+)
│   └── hardware/
│       ├── hardware.rst      # Hardware reference toctree
│       ├── cpn_r3_board.rst
│       ├── cpn_zeus_car_shield.rst
│       ├── cpn_esp_32_cam.rst
│       ├── cpn_camera_adapter.rst
│       ├── cpn_omni_grayscale_module.rst
│       ├── cpn_ultrasonic_module_xh.rst
│       ├── cpn_ir_obstacle_module.rst
│       ├── cpn_rgb_strip.rst
│       ├── cpn_tt_motor_xh.rst
│       ├── cpn_mecanum_wheel.rst
│       └── img/              # Hardware images
```

## conf.py — Per-Branch Settings

Key configuration lives in `docs/source/conf.py`:

```python
project = 'SunFounder Zeus Robot Car Kit for Arduino'
author = 'www.sunfounder.com'
html_theme = 'sphinx_rtd_theme'
extensions = [
    'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
]
# language = 'en'  # set per-branch; English is the default
```

The only thing that MUST change between language branches is the `language` setting
(if explicitly set). Everything else (extensions, html_theme, `rst_epilog` links
including `|link_german_tutorials|`, `|link_jp_tutorials|`, etc.) stays identical
to `docs`.

The `rst_epilog` contains replacement strings for language-switching links, IR remote
button icons, app UI icons, and external datasheet/reference links. These substitution
names remain the same across all branches — only the natural language of the `:ref:`
target pages differs.

## Requirements

```
sphinx==7.3.7
sphinx_rtd_theme>=3.0.2
sphinx_copybutton
```

## Working on This Repo

### Before starting any task
1. Confirm which branch you're on (`git branch --show-current`)
2. For documentation work, ensure you're on `docs` (English) or the correct language branch
3. Run `git pull` to ensure you have the latest from origin

### When making structural changes to `docs` (English)
1. Make changes to `docs` first
2. Verify the build: `cd docs && make html`
3. Commit on `docs`
4. Apply the same structural changes to each language branch (`docs-de`, `docs-es`,
   `docs-fr`, `docs-it`, `docs-ja`)
5. Push all branches

### When translating new content from `docs`
1. Identify the new/changed `.rst` files in `docs`
2. Copy the structural skeleton (toctrees, anchors, code blocks, directives) verbatim
3. Translate the prose — do NOT change toctrees, anchors, image paths, or code blocks
4. Verify heading underlines are longer than their heading text
5. Check inline markup: `**`, `` ` ``, `|sub|` followed by CJK letters or `（` need `\ ` escape
6. Build to check for Sphinx warnings: `cd docs && make html 2>&1`
7. Commit and push

### When adding/removing files
When a file is added to or removed from `docs`, the same file operation MUST be applied
to ALL language branches:

1. Create or delete the file on `docs` first
2. Update any parent toctree (`.. toctree::`) entries
3. Commit on `docs`
4. For each language branch:
   - If a file was **added**: create it with translated content (or a placeholder with
     the English content and a note to translate)
   - If a file was **deleted**: delete the corresponding translated file
   - Update the parent toctree
   - Commit
5. Push all branches

### Commit message style
Use descriptive commit messages:
```
add .gitignore and remove cpn_18650_battery documentation
docs: add new assembly instructions
docs(de): sync hardware.rst toctree with EN version
docs(ja): translate ar_move.rst
```

## Sync Operations Reference

### Cherry-picking a commit across all language branches
```bash
# From docs, after committing:
COMMIT=$(git rev-parse HEAD)

for branch in docs-de docs-es docs-fr docs-it docs-ja; do
    git checkout $branch
    git cherry-pick $COMMIT || {
        # If cherry-pick fails (e.g., file is translated differently):
        git cherry-pick --abort
        # Apply changes manually — delete/add files, edit toctrees
        # Then commit with the same message
    }
done

git push origin docs docs-de docs-es docs-fr docs-it docs-ja
git checkout docs
```

### Pushing all documentation branches
```bash
git push origin docs docs-de docs-es docs-fr docs-it docs-ja
```

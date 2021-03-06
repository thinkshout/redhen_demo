; This file was auto-generated by drush make
core = 7.x

api = 2
projects[drupal][version] = "7.12"

; RedHen module suite
projects[redhen][type] = "module"
projects[redhen][download][type] = "git"
projects[redhen][download][url] = "git://git.drupal.org/project/redhen.git"
projects[redhen][download][branch] = "master"

; RedHen dependencies
projects[relation][subdir] = "contrib"
projects[ctools] = "1.x-dev"
projects[ctools][subdir] = "contrib"
projects[registration][subdir] = "contrib"

; Modules we want to checkout to work on
projects[entity][type] = "module"
projects[entity][download][type] = "git"
projects[entity][download][url] = "git://git.drupal.org/project/entity.git"
projects[entity][download][branch] = "7.x-1.x"
projects[entity][subdir] = "contrib"

; Additional contrib modules and themes (Not required)
projects[admin_menu][subdir] = "contrib"
projects[addressfield][subdir] = "contrib"
projects[features][subdir] = "contrib"
projects[libraries][subdir] = "contrib"
projects[r4032login][subdir] = "contrib"
projects[superfish][subdir] = "contrib"
projects[strongarm][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[views][subdir] = "contrib"
projects[adaptivetheme][type] = "theme"
projects[at-commerce][type] = "theme"
projects[at-commerce] = "2.0-rc3"

; Developer tools
projects[devel][subdir] = "developer"
projects[diff][subdir] = "developer"
projects[ftools][subdir] = "developer"

; Additional libraries (Not required)
libraries[superfish][download][type] = "git"
libraries[superfish][download][url] = "git://github.com/mehrpadin/Superfish-for-Drupal.git"
libraries[superfish][directory_name] = "superfish"
libraries[superfish][type] = "library"

/*
   +----------------------------------------------------------------------+
   | PHP Version 5 / Imagick	                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 2006-2013 Mikko Koppanen, Scott MacVicar               |
   | Imagemagick (c) ImageMagick Studio LLC                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Mikko Kopppanen <mkoppanen@php.net>                          |
   |         Scott MacVicar <scottmac@php.net>                            |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_IMAGICK_MACROS_H
# define PHP_IMAGICK_MACROS_H

#define IMAGICK_ENSURE_NOT_EMPTY(magick_wand) \
	if(MagickGetNumberImages(magick_wand) == 0) { \
		php_imagick_throw_exception(IMAGICK_CLASS, "Can not process empty Imagick object" TSRMLS_CC); \
		return; \
	}

#define IMAGICK_FREE_MEMORY(type, value)\
	if (value != (type) NULL) { \
		value = (type) MagickRelinquishMemory(value); \
		value = (type)NULL; \
	}

#define IMAGICK_METHOD_DEPRECATED(class_name, method_name) \
	php_error(E_STRICT, "%s::%s method is deprecated and it's use should be avoided", class_name, method_name);

#define IMAGICK_METHOD_DEPRECATED_USE_INSTEAD(class_name, method_name, new_class, new_method) \
	php_error(E_STRICT, "%s::%s is deprecated. %s::%s should be used instead", class_name, method_name, new_class, new_method);

#endif /* PHP_IMAGICK_MACROS_H */

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

-- --------------------------------------------------------
-- `account`

CREATE TABLE IF NOT EXISTS `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `pseudo` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `hash_password` varchar(45) COLLATE utf8_unicode_ci NOT NULL,
  `session_token` varchar(45) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `email` varchar(45) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `gm_level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `join_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `last_ip` varchar(15) COLLATE utf8_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `banned` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `subscription_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci ;

-- --------------------------------------------------------
-- `ip_banned`

CREATE TABLE IF NOT EXISTS `ip_banned` (
  `ip` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `ban_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ban_reason` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `banned_by` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `unban_date` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------
-- `realm`

CREATE TABLE IF NOT EXISTS `realm` (
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `address` varchar(255) COLLATE utf8_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `port` smallint(5) unsigned NOT NULL DEFAULT '5556',
  `version` varchar(10) COLLATE utf8_unicode_ci NOT NULL DEFAULT '0.00.00',
  `community` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `player_limit` int(10) unsigned NOT NULL DEFAULT '500',
  `security_access_level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq_name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci ;


----------------------------------------------------------
--  `realm_configuration`

CREATE TABLE IF NOT EXISTS `realm_configuration` (
  `realm_id` tinyint(3) unsigned NOT NULL,
  `configuration_id` smallint(3) unsigned NOT NULL,
  `value` varchar(255) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `comment` varchar(255) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`realm_id`, `system_configuration_id`),
  FOREIGN KEY `fk_realm_info_realm_id` (`realm_id`) REFERENCES `realm`(`id`),
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci ;


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

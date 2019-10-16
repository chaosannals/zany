CREATE DEFINER=`toys`@`%` PROCEDURE `split_text`(
	IN raw LONGTEXT,
    IN sep VARCHAR(10)
)
BEGIN
	DECLARE segment VARCHAR(255);
	DECLARE segment_index INT UNSIGNED DEFAULT 0;
	DECLARE segment_count INT UNSIGNED DEFAULT 0;
    
    /* 计算分段数 */
    SET segment_count = 1 + (LENGTH(raw) - LENGTH(REPLACE(raw,sep,''))) / LENGTH(sep);
    
    /* 分割 */
    DROP TABLE IF EXISTS split_text_temporary;
    CREATE TEMPORARY TABLE split_text_temporary(
		item VARCHAR(255)
    );
    WHILE segment_index < segment_count
    DO
		SET segment_index = segment_index + 1;
        SET segment = REVERSE(SUBSTRING_INDEX(REVERSE(SUBSTRING_INDEX(raw,sep,segment_index)), REVERSE(sep), 1));
        INSERT INTO split_text_temporary VALUES (segment);
    END WHILE;
    
    SELECT * FROM split_text_temporary;
END
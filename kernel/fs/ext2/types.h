#ifndef EXT2_TYPES_H_
#define EXT2_TYPES_H_

#include <stdint.h>

typedef struct {
    uint32_t block_addr_bitmap;
    uint32_t block_addr_inode;
    uint32_t inode_table_block;
    uint16_t unallocated_blocks;
    uint16_t unallocated_inodes;
    uint16_t dir_cnt;
    uint16_t reserved[7];
} __attribute__((packed)) ext2_bgd_t;

typedef struct { 
    uint32_t inode_cnt;
    uint32_t block_cnt;
    uint32_t sb_reserved;
    uint32_t unallocated_blocks;
    uint32_t unallocated_inodes;
    uint32_t sb_block;
    uint32_t block_size;
    uint32_t frag_size;
    uint32_t blocks_per_group; 
    uint32_t frags_per_group;
    uint32_t inodes_per_group;
    uint32_t last_mnt_time;
    uint32_t last_written_time;
    uint16_t mnt_cnt;
    uint16_t mnt_allowed;
    uint16_t signature; 
    uint16_t fs_state;
    uint16_t error_response;
    uint16_t version_min;
    uint32_t last_fsck;
    uint32_t forced_fsck;
    uint32_t os_id;
    uint32_t version_maj; 
    uint16_t user_id;
    uint16_t group_id;

    uint32_t first_inode;
    uint16_t inode_size;
    uint16_t sb_bgd;
    uint32_t opt_features;
    uint32_t req_features; 
    uint32_t non_supported_features;
    uint64_t uuid[2];
    uint64_t volume_name[2];
    uint64_t last_mnt_path[8];
} __attribute__((packed)) ext2_superblock_t;

typedef struct {
    uint16_t permissions;
    uint16_t user_id;
    uint32_t size32l;
    uint32_t access_time;
    uint32_t creation_time;
    uint32_t mod_time;
    uint32_t del_time;
    uint16_t group_id;
    uint16_t hard_link_cnt;
    uint32_t sector_cnt;
    uint32_t flags;
    uint32_t oss1;
    uint32_t blocks[15];
    uint32_t gen_num;
    uint32_t eab;
    uint32_t size32h;
    uint32_t frag_addr;
} __attribute__((packed)) ext2_inode_t;

typedef struct {
    uint32_t inode;
    uint16_t entry_size;
    uint8_t name_length;
    uint8_t type;
    char name[];
} __attribute__((packed)) dir_entry_t;

typedef struct {
    ext2_superblock_t superblock;
    ext2_inode_t root_inode;
    uint64_t block_size;
    uint64_t frag_size;
    uint32_t bgd_cnt;
} ext2_fs_t;

#endif
